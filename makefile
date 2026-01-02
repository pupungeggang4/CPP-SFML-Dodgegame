linux:
	g++ src/main.cpp src/code/* -o main.out -Isrc/include -Ilib/SFML3/include -Llib/SFML3/lib -Wl,-rpath,lib/SFML3/lib -lsfml-graphics -lsfml-window -lsfml-system -std=c++17 -w

dummy:

