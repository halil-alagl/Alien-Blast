all:
	g++ src/Game.cpp -o Game -lsfml-graphics -lsfml-window -lsfml-system 
	./Game