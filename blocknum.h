#define _X_OPEN_SOURCE_EXTENDED
#include <cmath>
#include <string.h>
#include <ncurses.h>
#include <chrono>

using namespace std;




// proper print; moves back to initial pos after printing
void pprint(string str)
{
	int y, x;
	getyx(stdscr, y, x);

	// string to char[]
	char tab2[1024];
	strcpy(tab2, str.c_str());

	addstr(tab2);

	// move back to initial pos
	move(y, x);
}



void blocknum(int n)
{
	setlocale(LC_ALL, "");
	int y, x;
	getyx(stdscr, y, x);

	switch(n)
	{
		case 0:
			pprint("########"); move(y + 1, x);
			pprint("##    ##"); move(y + 2, x);
			pprint("##    ##"); move(y + 3, x);
			pprint("##    ##"); move(y + 4, x);
			pprint("##    ##"); move(y + 5, x);
			pprint("##    ##"); move(y + 6, x);
			pprint("########"); break;
		case 1:
			pprint("      ##"); move(y + 1, x);
			pprint("      ##"); move(y + 2, x);
			pprint("      ##"); move(y + 3, x);
			pprint("      ##"); move(y + 4, x);
			pprint("      ##"); move(y + 5, x);
			pprint("      ##"); move(y + 6, x);
			pprint("      ##"); break;
		case 2:
			pprint("########"); move(y + 1, x);
			pprint("      ##"); move(y + 2, x);
			pprint("      ##"); move(y + 3, x);
			pprint("########"); move(y + 4, x);
			pprint("##      "); move(y + 5, x);
			pprint("##      "); move(y + 6, x);
			pprint("########"); break;
		case 3:
			pprint("########"); move(y + 1, x);
			pprint("      ##"); move(y + 2, x);
			pprint("      ##"); move(y + 3, x);
			pprint("########"); move(y + 4, x);
			pprint("      ##"); move(y + 5, x);
			pprint("      ##"); move(y + 6, x);
			pprint("########"); break;
		case 4:
			pprint("##    ##"); move(y + 1, x);
			pprint("##    ##"); move(y + 2, x);
			pprint("##    ##"); move(y + 3, x);
			pprint("########"); move(y + 4, x);
			pprint("      ##"); move(y + 5, x);
			pprint("      ##"); move(y + 6, x);
			pprint("      ##"); break;
		case 5:
			pprint("########"); move(y + 1, x);
			pprint("##      "); move(y + 2, x);
			pprint("##      "); move(y + 3, x);
			pprint("########"); move(y + 4, x);
			pprint("      ##"); move(y + 5, x);
			pprint("      ##"); move(y + 6, x);
			pprint("########"); break;
		case 6:
			pprint("########"); move(y + 1, x);
			pprint("      ##"); move(y + 2, x);
			pprint("      ##"); move(y + 3, x);
			pprint("########"); move(y + 4, x);
			pprint("##    ##"); move(y + 5, x);
			pprint("##    ##"); move(y + 6, x);
			pprint("########"); break;
		case 7:
			pprint("########"); move(y + 1, x);
			pprint("      ##"); move(y + 2, x);
			pprint("      ##"); move(y + 3, x);
			pprint("      ##"); move(y + 4, x);
			pprint("      ##"); move(y + 5, x);
			pprint("      ##"); move(y + 6, x);
			pprint("      ##"); break;
		case 8:
			pprint("########"); move(y + 1, x);
			pprint("##    ##"); move(y + 2, x);
			pprint("##    ##"); move(y + 3, x);
			pprint("########"); move(y + 4, x);
			pprint("##    ##"); move(y + 5, x);
			pprint("##    ##"); move(y + 6, x);
			pprint("########"); break;
		case 9:
			pprint("########"); move(y + 1, x);
			pprint("##    ##"); move(y + 2, x);
			pprint("##    ##"); move(y + 3, x);
			pprint("########"); move(y + 4, x);
			pprint("      ##"); move(y + 5, x);
			pprint("      ##"); move(y + 6, x);
			pprint("########"); break;
	}

	move(y, x);
}