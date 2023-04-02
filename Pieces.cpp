#include "Pieces.h"

#include <curses.h>
#include <stdlib.h> // exit()

unsigned PieceHeight(const Piece &piece, Rotation rotation)
{
	switch(piece)
	{
	case PIECE_ONE:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 2;
		case ROTATION_90:
		case ROTATION_270:
			return 3;
		};
		break;
	case PIECE_TWO:
	case PIECE_THREE:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 4;
		case ROTATION_90:
		case ROTATION_270:
			return 2;
		};
		break;
	case PIECE_FOUR:
	case PIECE_SEVEN:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 3;
		case ROTATION_90:
		case ROTATION_270:
			return 2;
		};
		break;
	case PIECE_FIVE:
	case PIECE_EIGHT:
		return 3;
		break;
	case PIECE_SIX:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 2;
		case ROTATION_90:
		case ROTATION_270:
			return 4;
		};
		break;
	}

	std::exit(-1);
}

unsigned PieceWidth(const Piece &piece, Rotation rotation)
{
	switch(piece)
	{
	case PIECE_ONE:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 3;
		case ROTATION_90:
		case ROTATION_270:
			return 2;
		};
		break;
	case PIECE_TWO:
	case PIECE_THREE:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 2;
		case ROTATION_90:
		case ROTATION_270:
			return 4;
		};
		break;
	case PIECE_FOUR:
	case PIECE_SEVEN:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 2;
		case ROTATION_90:
		case ROTATION_270:
			return 3;
		};
		break;
	case PIECE_FIVE:
	case PIECE_EIGHT:
		return 3;
		break;
	case PIECE_SIX:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			return 4;
		case ROTATION_90:
		case ROTATION_270:
			return 2;
		};
		break;
	}

	std::exit(-1);
}

void DrawPiece(const Piece &piece, int y, int x, Rotation rotation)
{
	attrset(COLOR_PAIR(static_cast<int>(piece) % 8));

	switch(piece)
	{
	case PIECE_ONE:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			mvaddstr(y,     x,     "[][][]");
			mvaddstr(y + 1, x,     "[][][]");
			break;
		case ROTATION_90:
		case ROTATION_270:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x,     "[][]");
			mvaddstr(y + 2, x,     "[][]");
			break;
		};
		break;
	case PIECE_TWO:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
			mvaddstr(y,     x,     "[]");
			mvaddstr(y + 1, x,     "[][]");
			mvaddstr(y + 2, x,     "[]");
			mvaddstr(y + 3, x,     "[]");
			break;
		case ROTATION_90:
			mvaddstr(y,     x,     "[][][][]");
			mvaddstr(y + 1, x + 4, "[]");
			break;
		case ROTATION_180:
			mvaddstr(y,     x + 2, "[]");
			mvaddstr(y + 1, x + 2, "[]");
			mvaddstr(y + 2, x,     "[][]");
			mvaddstr(y + 3, x + 2, "[]");
			break;
		case ROTATION_270:
			mvaddstr(y,     x + 2, "[]");
			mvaddstr(y + 1, x,     "[][][][]");
			break;
		};
		break;
	case PIECE_THREE:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
			mvaddstr(y,     x + 2, "[]");
			mvaddstr(y + 1, x + 2, "[]");
			mvaddstr(y + 2, x + 2, "[]");
			mvaddstr(y + 3, x,     "[][]");
			break;
		case ROTATION_90:
			mvaddstr(y,     x,     "[]");
			mvaddstr(y + 1, x,     "[][][][]");
			break;
		case ROTATION_180:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x,     "[]");
			mvaddstr(y + 2, x,     "[]");
			mvaddstr(y + 3, x,     "[]");
			break;
		case ROTATION_270:
			mvaddstr(y,     x,     "[][][][]");
			mvaddstr(y + 1, x + 6, "[]");
			break;
		};
		break;
	case PIECE_FOUR:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x,     "[]");
			mvaddstr(y + 2, x,     "[][]");
			break;
		case ROTATION_90:
			mvaddstr(y,     x,     "[][][]");
			mvaddstr(y + 1, x,     "[]");
			mvaddstr(y + 1, x + 4, "[]"); // same line as above
			break;
		case ROTATION_180:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x + 2, "[]");
			mvaddstr(y + 2, x,     "[][]");
			break;
		case ROTATION_270:
			mvaddstr(y,     x,     "[]");
			mvaddstr(y,     x + 4, "[]"); // same line as above
			mvaddstr(y + 1, x,     "[][][]");
			break;
		};
		break;
	case PIECE_FIVE:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
		case ROTATION_180:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x + 2, "[]");
			mvaddstr(y + 2, x + 2, "[][]");
			break;
		case ROTATION_90:
		case ROTATION_270:
			mvaddstr(y,     x + 4, "[]");
			mvaddstr(y + 1, x,     "[][][]");
			mvaddstr(y + 2, x,     "[]");
			break;
		};
		break;
	case PIECE_SIX:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x + 2, "[][][]");
			break;
		case ROTATION_90:
			mvaddstr(y,     x + 2, "[]");
			mvaddstr(y + 1, x,     "[][]");
			mvaddstr(y + 2, x,     "[]");
			mvaddstr(y + 3, x,     "[]");
			break;
		case ROTATION_180:
			mvaddstr(y,     x,     "[][][]");
			mvaddstr(y + 1, x + 4, "[][]");
			break;
		case ROTATION_270:
			mvaddstr(y,     x + 2, "[]");
			mvaddstr(y + 1, x + 2, "[]");
			mvaddstr(y + 2, x,     "[][]");
			mvaddstr(y + 3, x,     "[]");
			break;
		};
		break;
	case PIECE_SEVEN:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x,     "[][]");
			mvaddstr(y + 2, x,     "[]");
			break;
		case ROTATION_90:
			mvaddstr(y,     x,     "[][][]");
			mvaddstr(y + 1, x + 2, "[][]");
			break;
		case ROTATION_180:
			mvaddstr(y,     x + 2, "[]");
			mvaddstr(y + 1, x,     "[][]");
			mvaddstr(y + 2, x,     "[][]");
			break;
		case ROTATION_270:
			mvaddstr(y,     x,     "[][]");
			mvaddstr(y + 1, x,     "[][][]");
			break;
		};
		break;
	case PIECE_EIGHT:
		switch(rotation)
		{
		default:
		case ROTATION_NONE:
			mvaddstr(y,     x + 4, "[]");
			mvaddstr(y + 1, x + 4, "[]");
			mvaddstr(y + 2, x,     "[][][]");
			break;
		case ROTATION_90:
			mvaddstr(y,     x,     "[]");
			mvaddstr(y + 1, x,     "[]");
			mvaddstr(y + 2, x,     "[][][]");
			break;
		case ROTATION_180:
			mvaddstr(y,     x,     "[][][]");
			mvaddstr(y + 1, x,     "[]");
			mvaddstr(y + 2, x,     "[]");
			break;
		case ROTATION_270:
			mvaddstr(y,     x,     "[][][]");
			mvaddstr(y + 1, x + 4, "[]");
			mvaddstr(y + 2, x + 4, "[]");
			break;
		};
		break;
	default:
		std::exit(-1);
		break;
	}
}

