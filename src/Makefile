CC=g++ -g -Wall -O0

app: main.o Application.o GameObject.o 
	$(CC) Application.o GameObject.o main.o -o app -lsfml-system -lsfml-window -lsfml-graphics

clean:
	rm ./app
	rm *.o

Application.o: Application.cpp ../headers/Application.h
	$(CC) -c Application.cpp

GameObject.o: GameObject.cpp ../headers/GameObject.h
	$(CC) -c GameObject.cpp

main.o: main.cpp ../headers/wrap_creation.h
	$(CC) -c main.cpp





