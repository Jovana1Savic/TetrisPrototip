#include "Board.h"


Board::Board() {

	for (int i = 0; i < BOARD_HEIGHT; mBoard[i++] = mBoardWithGhost[i] = 0x003F); // Create new empty board. 
	for (int i = 0; i < 3; mBoard[i++] = mBoardWithGhost[i] = 0xFFFF);
	/* Note that by setting the last 6 bits to 1 in cases in which the block starts at, for example,
	/ BLOCK_WIDTH-2 if there were parts that would collide with the edge they will be detected, if the
	 block starts at the same position but the last two columns are zero it will be possible to put it there. 
	 */
}
bool Board::putPiece(Block b, int rotation, int blockStartX)
{
	if (blockStartX < 0 || blockStartX >= BOARD_WIDTH )
		return false; // Tetromino's block start must definitely be between 0 and BOARD_WIDTH - 1.
	
	uint16_t TetrominoToPut = t.getTetromino(b, rotation);
	uint16_t row0 = (TetrominoToPut & 0x000F) << 12;
	uint16_t row1 = (TetrominoToPut & 0x00F0) << 8;
	uint16_t row2 = (TetrominoToPut & 0x0F00) << 4;
	uint16_t row3 = (TetrominoToPut & 0xF000);

	// Start from the bottom and go up until there's space for it. This also checks for collision with edges.
	// See constructor comments for more. 
	bool foundSpace = false; int i = 0;
	for (; i < BOARD_HEIGHT; i++) {

		uint16_t toCheckRow0 = (mBoard[i] << blockStartX) & 0xF000; 
		uint16_t toCheckRow1 = (mBoard[i + 1] << blockStartX) & 0xF000;
		uint16_t toCheckRow2 = (mBoard[i + 2] << blockStartX) & 0xF000;
		uint16_t toCheckRow3 = (mBoard[i + 3] << blockStartX) & 0xF000;

		if (!((toCheckRow0 & row0) || (toCheckRow1 & row1) || (toCheckRow2 & row2) || (toCheckRow3 & row3))) {
			foundSpace = true;
			break;
		}
	}

	if (!foundSpace)
		return false;
	
	// If there was space for the piece put it in the ghost board.
	mBoardWithGhost[i] |= (row0 ) >> blockStartX;
	mBoardWithGhost[i + 1] |= (row1) >> blockStartX;
	mBoardWithGhost[i + 2] |= (row2) >> blockStartX;
	mBoardWithGhost[i + 3] |= (row3) >> blockStartX;

	return true;
}
void Board::dropPiece()
{
	for (int i = 0; i < BOARD_HEIGHT; mBoard[i] = mBoardWithGhost[i++]);
}

void Board::drawBoard()
{
	for (int i = BOARD_HEIGHT - 1; i >= 3; i--) {
		std::cout << "|";
		for (int j = 0; j < 10; j++) {
			bool bit = mBoard[i] & (0x8000 >> j);
			if (bit)
				std::cout << "o";
			else
				std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
}
