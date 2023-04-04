#include "Demo.h"
#include "Pieces.h"

#include <curses.h>
#include <set>
#include <string>
#include <vector>

void DemoPieces()
{
	std::set rotations = {
		Rotation::ROTATION_NONE,
		Rotation::ROTATION_90,
		Rotation::ROTATION_180,
		Rotation::ROTATION_270,
	};
	for(auto rotation : rotations)
	{
		clear();

		int x, y;

		// Always same distance apart:
		x = 10;
		y = 2;
		for(auto i = 0; i < 8; ++i)
		{
			PieceData data = pieces.at(i);
			data = RotatePieceData(data, rotation);
			PD_DrawPiece(data, y, x, i);
			mvaddstr(y-1, x, "Piece");
			mvaddstr(y-1, x + 6, std::to_string(i + 1).c_str());
			x += 12;
		}

		// Always same width apart:
		x = 2;
		y = 10;
		for(auto i = 0; i < 8; ++i)
		{
			PieceData data = pieces.at(i);
			data = RotatePieceData(data, rotation);
			PD_DrawPiece(data, y, x, i);
			x += PD_PieceWidth(data) * 2 + 2;
		}
		// Always same height apart, sharing first piece with same-width row:
		x = 2;
		y = 10;
		{
			auto data = pieces.at(0);
			data = RotatePieceData(data, rotation);
			y += PD_PieceHeight(data) + 1;
		}
		for(auto i = 1; i < 8; ++i) // skip first
		{
			PieceData data = pieces.at(i);
			data = RotatePieceData(data, rotation);
			PD_DrawPiece(data, y, x, i);
			y += PD_PieceHeight(data) + 1;
		}

		getch();
	}

	std::vector<Flip> flips = {
		Flip::FLIP_NONE,
		Flip::FLIP_HORIZONTAL,
		Flip::FLIP_HORIZONTAL,
		Flip::FLIP_VERTICAL,
		Flip::FLIP_VERTICAL,
	};

	std::vector<PieceData> piece_data_to_flip;
	for(size_t p = 0; p < pieces.size(); ++p)
		piece_data_to_flip.push_back(pieces.at(p));
	for(const auto &flip : flips)
	{
		clear();
		int y = 2;
		int i = 0;
		for(auto &data : piece_data_to_flip)
		{
			FlipPieceData(data, flip);
			PD_DrawPiece(data, y, 2, i++);
			y += PD_PieceHeight(data) + 2;
		}
		getch();
	}

	move(8, 2);
}
