// i have never linked this many libraries i am not comfortable save me
// is my binary gonna be 100gb wow
#include <iostream>
#include <string.h>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include <sstream>

#include "blocknum.h"
#include "datefmt.h"

using namespace std;


int centerx()
{
	int y, x;
	getmaxyx(stdscr, y, x);

	int cx = floor(x / 2);

	return cx;
}

int centery()
{
	int y, x;
	getmaxyx(stdscr, y, x);
	
	int cy = floor(y / 2);

	return cy;
}

void pcenter(string str)
{
	int y, x;
	getmaxyx(stdscr, y, x);
	
	if(str.length() % 2 == 0)
	{
		int offset = str.length() / 2;
		int tox = (x / 2) - offset;
		
		move(y, tox);
		addstr(str.c_str());
	}
}

int main(int argc, char **argv)
{
	// defaults (if no arg to override)
	int refreshr = 60;

	// args
	for(int i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "bruh") == 0)
		{
			cout << "ok";
		}else
		if(strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--time") == 0)
		{
			if(argv[i + 1])
			{
				refreshr = atoi(argv[i + 1]);
			}else
			{
				cout << "No value passed for flag '--time'. Exiting" << '\n';
				return 0;
			}
		}
	}



	initscr(); 
	noecho(); // prevents echoing typed chars
	curs_set(0); // hide cursor

	
	
	bool i = false;
	while(true)
	{
		clear();
		int y, x;
		getyx(stdscr, y, x);

		map<string, string> date = datefmt();

		
		// grabs current time from table. check headers for better context
		string hour1_t = date["hour1"];
		string hour2_t = date["hour2"];
		string min1_t  = date["minute1"];
		string min2_t  = date["minute2"];

		// hour & min to int
		int hour1_i = stoi(hour1_t);
		int hour2_i = stoi(hour2_t);
		int min1_i = stoi(min1_t);
		int min2_i = stoi(min2_t);
		
		int cy = centery();
		cy -= 2; // move 2 cells up from absolute center
		move(cy, centerx());
		pcenter("##");

		cy = centery();
		cy += 2; // move 2 cells down from absolute center
		move(cy, centerx());
		pcenter("##");

		
		move(centery() - 3, centerx() - 10);
		blocknum(hour2_i);
		move(centery() - 3, centerx() - 20);
		blocknum(hour1_i);
		
		move(centery() - 3, centerx() + 4);
		blocknum(min1_i);
		move(centery() - 3, centerx() + 14);
		blocknum(min2_i);
		
		string outdate = date["month"] + ' ' + date["day"] + date["ordinal"] + ", " + date["year"];
		// string outdate = "deez nuts its 2020 i think lmao";
		move(centery() + 5, centerx() - (outdate.length() / 2));
		addstr(outdate.c_str());


		refresh();
		i = true; // i only = false on first loop. used for syncing

		sleep(refreshr);
	}
} 
