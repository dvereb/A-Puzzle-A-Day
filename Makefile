build/apad: main.cpp Pieces.cpp
	mkdir -p build
	clang++ -g -O0 -std=c++17 -o $@ $^ -lncurses

clean:
	rm build/apad
	rmdir build/
