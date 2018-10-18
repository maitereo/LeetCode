CXX := g++
CFLAGS := -I./ -g -Og -std=c++14
LDFLAGS :=

all: build

build: main.cpp Clone.h ListConstructor.h RandomList.h
	$(CXX) $(CFLAGS) $(LDFLAGS) main.cpp -o Solution

run: build
	./Solution

.PHONY: clean

clean:

