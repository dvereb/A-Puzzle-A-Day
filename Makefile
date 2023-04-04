build/apad: main.cpp Pieces.cpp Pieces.h Demo.cpp Demo.h
	mkdir -p build
	clang++ -g -O0 -std=c++17 -o $@ main.cpp Pieces.cpp Demo.cpp -lncurses

clean:
	rm build/apad
	rmdir build/
