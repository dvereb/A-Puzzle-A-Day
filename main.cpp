#include "Pieces.h"

#include <curses.h>
#include <signal.h>

#include <string>
#include <unordered_map>

static void finish(int sig);
void init_colors();

int main(int argc, char *argv[])
{
	initscr();             /* initialize the curses library */
	keypad(stdscr, TRUE);  /* enable keyboard mapping */
	nonl();                /* tell curses not to do NL->CR/NL on output */
	cbreak();              /* take input chars one at a time, no wait for \n */
	echo();                /* echo input - in color */

	if(has_colors())
		init_colors();

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
