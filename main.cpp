#include "Demo.h"
#include "Pieces.h"

#include <curses.h>
#include <signal.h>

#include <set>
#include <string>
#include <unordered_map>

static void finish(int sig);
void init_colors();

void PlacePiece(Piece piece, const std::vector<Flip> &flips, Rotation rotation, int y, int x);
std::string PlaceName(unsigned int position);
void GetPosition(unsigned long position, int &y, int &x);

void DrawGrid(int y = 0, int x = 0);

int main(int argc, char *argv[])
{
	initscr();             /* initialize the curses library */
	keypad(stdscr, TRUE);  /* enable keyboard mapping */
	nonl();                /* tell curses not to do NL->CR/NL on output */
	cbreak();              /* take input chars one at a time, no wait for \n */
	echo();                /* echo input - in color */

	if(has_colors())
		init_colors();

	if(argc == 2 && std::string(argv[1]) == "-d")
	{
		DemoPieces();

		finish(0);
	}

	// for each piece passed in, render it:
	{
		DrawGrid();
		int x = 1;
		int y = 1;
		auto count = 0;
		for(auto input = 1; input < argc; ++input)
		{
			try {
				unsigned long input_val = std::atoi(argv[input]);
				Piece piece = 0b111 & input_val;
				Flip horizontal = (0b1000 & input_val) ? Flip::FLIP_HORIZONTAL : Flip::FLIP_NONE;
				Flip vertical = (0b10000 & input_val) ? Flip::FLIP_VERTICAL : Flip::FLIP_NONE;
				Rotation rotation = static_cast<Rotation>((0b1100000 & input_val) >> 5);
				unsigned long position = (0b1111110000000 & input_val) >> 7;
				GetPosition(position, y, x);
				PlacePiece(piece,
				           { horizontal, vertical },
				           rotation,
				           y,
				           x * 2);
				// y += PD_PieceHeight(pieces.at(piece)) + 1;
				y += 5;
			} catch(const std::exception &e) {
				mvaddstr(y, 1, "std::atoi error");
				y += 3;
			}
			if(++count > 7)
			{
				count = 0;
				y = 1;
				x += 10;
			}
		}
	}

	int num = 0;
	while(true)
	{
		int c = getch();     /* refresh, accept single keystroke of input */
		attrset(COLOR_PAIR(num++ % 8));

		/* process the command keystroke */
	}

	finish(0);
}

// NOTE(dev): ALways execute so we don't screw up our terminal.
static void finish(int sig)
{
	endwin();
	std::exit(0);
}

void init_colors()
{
	start_color();

	/*
	 * Simple color assignment, often all we need.  Color pair 0 cannot
	 * be redefined.  This example uses the same value for the color
	 * pair as for the foreground color, though of course that is not
	 * necessary:
	 */
	init_pair(1, COLOR_RED,     COLOR_BLACK);
	init_pair(2, COLOR_GREEN,   COLOR_BLACK);
	init_pair(3, COLOR_YELLOW,  COLOR_BLACK);
	init_pair(4, COLOR_BLUE,    COLOR_BLACK);
	init_pair(5, COLOR_CYAN,    COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE,   COLOR_BLACK);
}

void PlacePiece(Piece piece, const std::vector<Flip> &flips, Rotation rotation, int y, int x)
{
	PieceData data = pieces.at(piece);

	for(Flip flip : flips)
		FlipPieceData(data, flip);

	data = RotatePieceData(data, rotation);

	PD_DrawPiece(data, y, x, piece);
}

std::string PlaceName(unsigned int position)
{
	static const std::vector<std::string> months =
		{ "JA", "FE", "MR", "AP", "MY", "JN", "JL", "AU", "SE", "OC", "NO", "DE", };

	if(position < 12)
		return months[position];

	auto rtn = std::to_string(position - 11);
	if(rtn.size() == 1)
		rtn = "0" + rtn;
	return rtn;
}

void GetPosition(unsigned long position, int &y, int &x)
{
	if(position < 6)
	{
		y = 0;
		x = position;
		return;
	}

	if(position < 12)
	{
		y = 1;
		x = position - 6;
		return;
	}

	if(position < 19)
	{
		y = 2;
		x = position - 12;
		return;
	}

	if(position < 26)
	{
		y = 3;
		x = position - 19;
		return;
	}

	if(position < 33)
	{
		y = 4;
		x = position - 26;
		return;
	}

	if(position < 40)
	{
		y = 5;
		x = position - 33;
		return;
	}

	if(position < 43)
	{
		y = 6;
		x = position - 40;
		return;
	}

	x = y = 0;
	return;
}

void DrawGrid(int y, int x)
{
	// DEBUG: Draw Grid
	for(auto row = 0; row < 2; ++row)
		for(auto col = 0; col < 6; ++col)
			mvaddstr(y+ row, x + col * 2, PlaceName((6 * row) + col).c_str());
	for(auto row = 2; row < 6; ++row)
		for(auto col = 0; col < 7; ++col)
			mvaddstr(y +row, x + col * 2, PlaceName(12 + (7 * (row - 2) + col)).c_str());
	for(auto col = 0; col < 3; ++col)
		mvaddstr(y + 6, x + col * 2, PlaceName(40 + col).c_str());
}
