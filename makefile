install:
	clang++ -pthread -std=c++17 -o cclock main.cpp -lncurses
	mv cclock /usr/local/bin/cclock

uninstall:
	rm -rf /usr/local/bin/cclock
