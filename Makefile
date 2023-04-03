build/apad: main.cpp Pieces.cpp Pieces.h
	mkdir -p build
	clang++ -g -O0 -std=c++17 -o $@ main.cpp Pieces.cpp -lncurses

clean:
	rm build/apad
	rmdir build/
