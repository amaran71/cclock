#include <iostream>
#include <sstream>
#include <map>
#include <chrono>

// using namespace std;
using std::string;
using std::map;
using std::cout;
using std::stringstream;


map<string, string> datefmt()
{
	// get current time
	auto timey = std::chrono::system_clock::now();
	time_t end_time = std::chrono::system_clock::to_time_t(timey);
	string timeout = std::ctime(&end_time);


	// init array to split into
	string arr[5];
	int i = 0;

	// sstream confuses me
	stringstream ssin(timeout);
	while (ssin.good() && i < 5)
	{
		ssin >> arr[i];
		++i;
	}

	map<string, string> day = {
		{ "Fri", "friday"    },
		{ "Sun", "sunday"    },
		{ "Sat", "saturday"  },
		{ "Mon", "monday"    },
		{ "Tue", "tuesday"   },
		{ "Wed", "wednesday" },
		{ "Thu", "thursday"  }
	};

	map<string, string> month = {
		{ "Jan", "january"   },
		{ "Feb", "february"  },
		{ "Mar", "march"     },
		{ "Apr", "april"     },
		{ "May", "may"       },
		{ "Jun", "june"      },
		{ "Jul", "july"      },
		{ "Aug", "augest"    },
		{ "Sep", "september" },
		{ "Oct", "october"   },
		{ "Nov", "november"  },
		{ "Dec", "december"  }
	};

	// substr's time into seperate h:m:s values
	string ttime = arr[3];
		string hour1 = ttime.substr(0, 1);
		string hour2 = ttime.substr(1, 1);
		string min1  = ttime.substr(3, 1);
		string min2  = ttime.substr(4, 1);
		string sec  = ttime.substr(6, 2);

	// weekday
	string wd = day[arr[0]];
	// month
	string mo = month[arr[1]];
	// day (num)
	string da = arr[2];
	// year
	string ye = arr[4];
	
	string od;
	switch(da.at(1))
	{
		case '1':
			od = "st";
			break;
		case '2':
			od = "nd";
			break;
		case '3':
			od = "rd";
			break;
		default:
			od = "th";
			break;
	}

	map<string, string> output = {
		{ "weekday", wd   },
		{ "day",     da   },
		{ "ordinal", od   },
		{ "month",   mo   },
		{ "year",    ye   },

		{ "hour1",  hour1 },
		{ "hour2",  hour2 },
		{ "minute1", min1 },
		{ "minute2", min2 },
		{ "second",  sec  }
	};

	return output;
}

string gettime()
{
	// get current time
	auto timey = std::chrono::system_clock::now();
	time_t end_time = std::chrono::system_clock::to_time_t(timey);
	string timeout = std::ctime(&end_time);
	
	return timeout;
}