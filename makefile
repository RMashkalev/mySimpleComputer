all: main.cpp memory.cpp terminal.cpp
		g++ -Wall -o sc $^
clean:
		rm sc 