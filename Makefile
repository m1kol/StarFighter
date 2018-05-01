CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=-o -libsfml-system -libsfml-window -libsfml-graphics

#SOURCES=src/main.cpp src/Application.cpp src/Application.h src/GameObject.cpp src/GameObject.h
#OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=StarFighter

#all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): main.o Application.o GameObject.o
	$(CC) $(LDFLAGS) main.o Application.o GameObject.o

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp

Application.o: src/Application.cpp headers/Application.h
	$(CC) $(CFLAGS) src/Application.cpp headers/Application.h

GameObject.o: src/GameObject.cpp headers/GameObject.h
	$(CC) $(CFLAGS) src/GameObject.cpp headers/GameObject.h
