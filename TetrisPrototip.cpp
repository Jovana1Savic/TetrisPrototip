// TetrisPrototip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Board.h"


int main()
{
	Board b;
	b.drawBoard();
	b.putPiece(T, 0, 0);
	b.dropPiece();
	b.drawBoard();
	b.putPiece(J, 1, 2);
	b.dropPiece();
	b.drawBoard();
    return 0;
}

