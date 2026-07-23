all:
	g++ src/Game.cpp src/Bullet.cpp -o Game -lsfml-graphics -lsfml-window -lsfml-system 
	./Game