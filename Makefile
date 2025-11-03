CC      = g++
OBJS    = main.o commands.o

.PHONY: all run clean

all: main

main: $(OBJS)
	$(CC) $(OBJS) -o $@

main.o: main.cpp commands.h
commands.o: commands.cpp commands.h

run: main
	./main

clean:
	rm -f main $(OBJS)s