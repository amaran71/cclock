// i have never linked this many libraries i am not comfortable save me
// is my binary gonna be 100gb wow
#include <iostream>
#include <string.h>
#include <ncurses.h>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include <sstream>

#include "blocknum.h"
#include "datefmt.h"

using namespace std;



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
			if(argv[i + 1]) {
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
		map<string, string> date = datefmt();

		// grabs current time from table. check headers for better context
		string hour_t = date["hour"];
		string min_t  = date["min"];

		// hour & min to int
		int hour_i = stoi(hour_t);
		int min_i  = stoi(min_t);


		cout << hour_i;

		refresh();
		i = true; // i only = false on first loop. used for syncing

		sleep(refreshr);
	}
} 
