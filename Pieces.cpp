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

PieceData RotatePieceData(const PieceData &data, Rotation rotation)
{
	PieceData rtn;

	if(!data.size())
		return rtn;
	if(!data[0].size())
		return rtn;

	// Step 1: Size it:
	switch(rotation)
	{
	default:
	case Rotation::ROTATION_NONE:
	case Rotation::ROTATION_180:
		rtn.resize(data.size());
		for(auto &row : rtn)
			row.resize(data[0].size());
		break;
	case Rotation::ROTATION_90:
	case Rotation::ROTATION_270:
		rtn.resize(data[0].size());
		for(auto &row : rtn)
			row.resize(data.size());
		break;
	};

	switch(rotation)
	{
	default:
	case Rotation::ROTATION_NONE:
		rtn = data;
		break;
	case Rotation::ROTATION_90:
		rtn = data;
		// TODO(dev):
		// TODO(dev): x's become y's
		// TODO(dev): y's become max x - x's
		// TODO(dev):
		break;
	case Rotation::ROTATION_180:
		for(size_t row = 0; row < data.size(); ++row)
		{
			size_t opposite_row = data.size() - row - 1;
			for(size_t col = 0; col < data[row].size(); ++col)
			{
				size_t opposite_col = data[opposite_row].size() - col - 1;
				rtn[opposite_row][opposite_col] = data[row][col];
			}
		}
		break;
	case Rotation::ROTATION_270:
		rtn = data;
		// TODO(dev):
		// TODO(dev): I mean we could just rotate 90 & then 180,
		// TODO(dev):  but that seems like the cheap way out.
		// TODO(dev):
		break;
	};

	return rtn;
}

unsigned PD_PieceHeight(const PieceData &data)
{
	return data.size();
}
unsigned PD_PieceWidth(const PieceData &data)
{
	size_t rtn = 0;
	for(auto row : data)
		rtn = std::max(rtn, row.size());
	return rtn;
}

unsigned PD_PieceHeight(const Piece &piece, Rotation rotation)
{
	switch(rotation)
	{
	default:
	case Rotation::ROTATION_NONE:
	case Rotation::ROTATION_180:
		return pieces.at(piece).size();
		break;
	case Rotation::ROTATION_90:
	case Rotation::ROTATION_270:
		return PD_PieceHeight(RotatePieceData(pieces.at(piece), Rotation::ROTATION_90));
		break;
	};
}

unsigned PD_PieceWidth(const Piece &piece, Rotation rotation)
{
	size_t rtn = 0;
	for(auto row : pieces.at(piece))
		rtn = std::max(rtn, row.size());
	return rtn;
}

void PD_DrawPiece(const Piece &piece, int y, int x, Rotation rotation)
{
	attrset(COLOR_PAIR(static_cast<int>(piece) % 8));

	auto data = RotatePieceData(pieces.at(piece), rotation);
	for(size_t row = 0; row < data.size(); ++row)
	{
		for(size_t col = 0; col < data[row].size(); ++col)
		{
			if(data[row][col])
				mvaddstr(y + row, x + (col * 2), "[]");
		}
	}
}
