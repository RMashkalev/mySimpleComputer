OFLAGS=gcc -Wall -c -o
BINFLAGS=gcc -Wall -o

all: bin/sc
bin/sc: obj/main.o obj/memory.o obj/terminal.o
	$(BINFLAGS) $@ $^
obj/main.o: src/main.c
	$(OFLAGS) $@ $^
obj/memory.o: src/memory.c
	$(OFLAGS) $@ $^
obj/terminal.o: src/terminal.c
	$(OFLAGS) $@ $^

clean:
		rm bin/sc obj/*.o