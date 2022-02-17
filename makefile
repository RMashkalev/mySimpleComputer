OFLAGS=gcc -Wall -c -o
BINFLAGS=gcc -Wall -o

all: bin/sc
bin/sc: main.cpp memory.cpp terminal.cpp
	$(BINFLAGS) $@ $^
bin/sc: obj/main.o memory.o terminal.o
	$(OFLAGS) $@ $^
obj/main.o: src/main.cpp
	$(OFLAGS) $@ $^
obj/memory.o: src/memory.cpp
	$(OFLAGS) $@ $^
obj/terminal.o: src/terminal.cpp
	$(OFLAGS) $@ $^

clean:
		rm sc 