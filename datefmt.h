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
		string hour = ttime.substr(0, 2);
		string min  = ttime.substr(3, 2);
		string sec  = ttime.substr(6, 2);

	// weekday
	string wd = day[arr[0]];
	// month
	string mo = month[arr[1]];
	// day (num)
	string da = arr[2];
	// year
	string ye = arr[3];

	map<string, string> output = {
		{ "weekday", wd   },
		{ "day",     da   },
		{ "month",   mo   },
		{ "year",    ye   },

		{ "hour",    hour },
		{ "minute",  min  },
		{ "second",  sec  }
	};

	return output;
}