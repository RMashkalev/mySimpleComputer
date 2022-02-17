OFLAGS=g++ -Wall -o
BINFLAGS=g++ -Wall -o

all: bin/sc
bin/sc: obj/main.o obj/memory.o obj/terminal.o
	$(BINFLAGS) $@ $^
obj/main.o: src/main.cpp
	$(OFLAGS) $@ $^
obj/memory.o: src/memory.cpp
	$(OFLAGS) $@ $^
obj/terminal.o: src/terminal.cpp
	$(OFLAGS) $@ $^

clean:
		rm sc 