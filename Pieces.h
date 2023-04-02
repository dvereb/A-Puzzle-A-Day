#ifndef APAD_PIECES_H
#define APAD_PIECES_H

#include <stdint.h>

enum Rotation {
	ROTATION_NONE,
	ROTATION_90,
	ROTATION_180,
	ROTATION_270,
};

#define NUM_PIECES 8
typedef uint8_t Piece; // only need literally 8, not 8 bits, but hey.

#define PIECE_ONE   0x0
/*
 *   [][][]
 *   [][][]
 */

#define PIECE_TWO   0x1
/*
 *   []
 *   [][]
 *   []
 *   []
 */

#define PIECE_THREE 0x2
/*
 *     []
 *     []
 *     []
 *   [][]
 */

#define PIECE_FOUR  0x3
/*
 *   [][]
 *   []
 *   [][]
 */

#define PIECE_FIVE  0x4
/*
 *   [][]
 *     []
 *     [][]
 */

#define PIECE_SIX   0x5
/*
 *   [][]
 *     [][][]
 */

#define PIECE_SEVEN 0x6
/*
 *   [][]
 *   [][]
 *   []
 */

#define PIECE_EIGHT 0x7
/*
 *       []
 *       []
 *   [][][]
 */

unsigned PieceHeight(const Piece &piece,
                     Rotation rotation = Rotation::ROTATION_NONE);
unsigned PieceWidth(const Piece &piece,
                    Rotation rotation = Rotation::ROTATION_NONE);
void DrawPiece(const Piece &piece, int y, int x,
               Rotation rotation = Rotation::ROTATION_NONE);

#endif
