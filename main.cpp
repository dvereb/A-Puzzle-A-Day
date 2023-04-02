#include "Pieces.h"

#include <curses.h>
#include <signal.h>

#include <set>
#include <string>
#include <unordered_map>

static void finish(int sig);
void init_colors();

// DEBUG:
void DemoPieces();

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
		int y = 1;
		for(auto input = 1; input < argc; ++input)
		{
			try {
				Piece piece = 0b111 & std::atoi(argv[input]);
				DrawPiece(piece, y, 1);
				y += PieceHeight(piece) + 1;
			} catch(const std::exception &e) {
				mvaddstr(y, 1, "std::atoi error");
				y += 2;
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
		int x = 1;
		for(auto i = 0; i < 8; ++i)
		{
			Piece piece = static_cast<Piece>(i);
			DrawPiece(piece, 2, x, rotation);
			x += 12;
		}
		getch();
	}
	move(8, 2);
}
