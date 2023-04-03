#ifndef APAD_PIECES_H
#define APAD_PIECES_H

#include <stdint.h>
#include <unordered_map>
#include <vector>

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

typedef std::vector<std::vector<bool>> PieceData;
const std::unordered_map<Piece, PieceData> pieces =
{
	{
		PIECE_ONE,
		{
			{ true,  true,  true, },
			{ true,  true,  true, },
		}
	},
	{
		PIECE_TWO,
		{
			{ true,  false, },
			{ true,  true,  },
			{ true,  false, },
			{ true,  false, },
		}
	},
	{
		PIECE_THREE,
		{
			{ false, true,  },
			{ false, true,  },
			{ false, true,  },
			{ true,  true,  },
		}
	},
	{
		PIECE_FOUR,
		{
			{ true,  true,  },
			{ true,  false, },
			{ true,  true,  },
		}
	},
	{
		PIECE_FIVE,
		{
			{ true,  true,  false, },
			{ false, true,  false, },
			{ false, true,  true,  },
		}
	},
	{
		PIECE_SIX,
		{
			{ true,  true,  false, false, },
			{ false, true,  true,  true,  },
		}
	},
	{
		PIECE_SEVEN,
		{
			{ true,  true,  },
			{ true,  true,  },
			{ true,  false, },
		}
	},
	{
		PIECE_EIGHT,
		{
			{ false, false, true,  },
			{ false, false, true,  },
			{ true,  true,  true,  },
		}
	},
};

unsigned PieceHeight(const Piece &piece,
                     Rotation rotation = Rotation::ROTATION_NONE);
unsigned PieceWidth(const Piece &piece,
                    Rotation rotation = Rotation::ROTATION_NONE);
void DrawPiece(const Piece &piece, int y, int x,
               Rotation rotation = Rotation::ROTATION_NONE);

PieceData RotatePieceData(const PieceData &data, Rotation rotation);
unsigned PD_PieceHeight(const PieceData &data);
unsigned PD_PieceHeight(const Piece &piece,
                     Rotation rotation = Rotation::ROTATION_NONE);
unsigned PD_PieceWidth(const PieceData &data);
unsigned PD_PieceWidth(const Piece &piece,
                    Rotation rotation = Rotation::ROTATION_NONE);
void PD_DrawPiece(const Piece &piece, int y, int x,
                  Rotation rotation = Rotation::ROTATION_NONE);

#endif
