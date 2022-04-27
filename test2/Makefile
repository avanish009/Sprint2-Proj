CC = g++
CFLAGS = -g  -Wall -Wextra 

INCLUDES = -I ./

run: main.o TripPlanner.o Airline.o Hotel.o
	${CC} ${CFLAGS} main.o TripPlanner.o  Airline.o Hotel.o -o run

main.o: main.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c main.cpp

TripPlanner.o: TripPlanner.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c TripPlanner.cpp

Airline.o: Airline.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c Airline.cpp

Hotel.o: Hotel.cpp
	${CC} ${CFLAGS} ${INCLUDES} -c Hotel.cpp


clean:
	echo "Cleaning....."
	rm *.o run
