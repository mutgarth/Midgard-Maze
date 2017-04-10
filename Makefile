CC := g++
CFLAGS := -Wall -lncurses

SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/saida -lncurses

obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc -lncurses

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*

run:
	bin/saida
