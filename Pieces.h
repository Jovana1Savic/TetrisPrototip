/*
@brief	Here we define pieces as they will be stored in ROM memory. 
@detail	Each piece has its own 4x4 block which is filled based on piece and
		its rotation. The piece and its rotation will be represented by 16
		bit numbers where 1 in binary form of that number means that the 
		corresponding block is filled. 
		i.e. Piece J  and its rotations are given as:

		0 0 0 0
		0 0 1 0		->		0x0226
		0 0 1 0
		0 1 1 0 

		0 0 0 0
		1 1 1 0		->		0x0E20
		0 0 1 0
		0 0 0 0 

		0 0 0 0
		1 1 0 0		->		0x0C88
		1 0 0 0
		1 0 0 0

		0 0 0 0
		0 0 0 0		->		0x008E
		1 0 0 0
		1 1 1 0

		The center of rotation is, except for tetrimino I in the second column of third row. 

@version 1.0
@author Jovana Savic
@date	29/3/2018
*/

#pragma once
#include "stdafx.h"
#include "stdint.h"

enum Block {L, J, Z, S, T, O, I};

class Tetromino {

public:
	uint16_t getTetromino(Block t, int rotation) {
		int index = 0;
		switch (t) {
			case L: index = 0; break;
			case J: index = 1; break;
			case Z: index = 2; break;
			case S: index = 3; break;
			case T: index = 4; break;
			case O: index = 5; break;
			case I: index = 6; break;
		}
		return TetrominosROM[index * 4 + rotation % 4];
	}

private:
	uint16_t TetrominosROM[28] = {

		// Tertromino L
		0x088C, 0x002E, 0x0622, 0x0E80,
		// Tertromino J
		0x0226, 0x0E20, 0x0C88, 0x008E,
		// Tetromino Z
		0x00C6, 0x0264, 0x0C60, 0x04C8,
		// Tetromino S
		0x006C, 0x0462, 0x06C0, 0x08C4,
		// Tetromino T
		0x004E, 0x0262, 0x0E40, 0x08C8,
		// Tetromino O
		0x00CC, 0x0066, 0x0660, 0x0CC0,
		// Tetromino I
		0x8888, 0x000F, 0x1111, 0xF000
	};

};