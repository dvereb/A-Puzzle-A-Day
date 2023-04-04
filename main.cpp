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
				PlacePiece(piece,
				           { horizontal, vertical },
				           rotation,
				           y,
				           x);
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
