# Makefile

RallyGame : main.o Game.o TextureManager.o GameObject.o Player.o Obstacle.o Speedometer.o Odometer.o
	g++ -g -Wall -o RallyGame main.o Game.o TextureManager.o GameObject.o Player.o Obstacle.o Speedometer.o Odometer.o -lSDL2 -lSDL2_image

main.o : main.cpp Game.h
	g++ -g -Wall -c main.cpp -lSDL2 -lSDL2_image

Game.o : Game.cpp Game.h TextureManager.h Player.h Obstacle.o Speedometer.o Utils.h
	g++ -g -Wall -c Game.cpp -lSDL2 -lSDL2_image

GameObject.o : GameObject.cpp GameObject.h TextureManager.h Geometry.h
	g++ -g -Wall -c GameObject.cpp -lSDL2 -lSDL2_image

TextureManager.o : TextureManager.cpp TextureManager.h
	g++ -g -Wall -c TextureManager.cpp -lSDL2 -lSDL2_image	

Speedometer.o : Speedometer.cpp Speedometer.h GameObject.h Utils.h
	g++ -g -Wall -c Speedometer.cpp -lSDL2 -lSDL2_image

Odometer.o : Odometer.cpp Odometer.h GameObject.h Utils.h
	g++ -g -Wall -c Odometer.cpp -lSDL2 -lSDL2_image	

Obstacle.o : Obstacle.cpp Obstacle.h GameObject.h Utils.h
	g++ -g -Wall -c Obstacle.cpp -lSDL2 -lSDL2_image	
	
Player.o : Player.cpp Player.h GameObject.h Utils.h
	g++ -g -Wall -c Player.cpp -lSDL2 -lSDL2_image

clean:
	rm -f RallyGame *.o