/*
@brief	This file contains description of the class board.
@detail	The board is represented as a 20x10 matrix. If 
		the position is filled it has value 1, else 0. 

@version 1.0
@author Jovana Savic
@date	29/3/2018
*/

#pragma once


#include "Pieces.h"
#include <iostream>

//	Defines

#define BOARD_LINE_WIDTH 6          // Width of each of the two lines that delimit the board.
#define BLOCK_SIZE 16               // Width and Height of each block of a piece.
#define BOARD_POSITION 320          // Center position of the board from the left of the screen.
#define BOARD_WIDTH 10              // Board width in blocks.
#define MAX_BOARD_WIDTH 16			// Maximum board width in blocks. 
#define BOARD_HEIGHT 23             // Board height in blocks.
#define MIN_VERTICAL_MARGIN 20      // Minimum vertical margin for the board limit.      
#define MIN_HORIZONTAL_MARGIN 20    // Minimum horizontal margin for the board limit.
#define PIECE_BLOCKS 4              // Number of horizontal and vertical blocks of a matrix piece.

class Board {

public:
	Board(); // Create empty board.
	bool putPiece(Block b, int rotation, int blockStartX); // Puts ghost piece into the board, if possible. 
	void dropPiece(); // Puts the current ghost piece into the board. 
	void drawBoard();
private:
	// Each row will be represented as one 16bit integer. Row with index 3 is the bottom one. MSB of the number is 
	// the first column. The first three rows are "dummy" rows, used to generalize cases in which bottom 3 rows
	// in some rotation are empty. 
	uint16_t mBoard[BOARD_HEIGHT];  
	uint16_t mBoardWithGhost[BOARD_HEIGHT]; // The state that the board will have if the piece is dropped. 
	Tetromino t; // ROM memory
};