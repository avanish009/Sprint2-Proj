CC = g++
CFLAGS = -g  -Wall -Wextra 
CCOV = -fprofile-arcs -ftest-coverage

INCLUDES = -I ./

run: main.o TripPlanner.o Airline.o Hotel.o
	${CC} ${CFLAGS} ${CCOV} main.o TripPlanner.o  Airline.o Hotel.o -o run

main.o: main.cpp
	${CC} ${CFLAGS} ${CCOV} ${INCLUDES} -c main.cpp

TripPlanner.o: TripPlanner.cpp
	${CC} ${CFLAGS} ${CCOV} ${INCLUDES} -c TripPlanner.cpp

Airline.o: Airline.cpp
	${CC} ${CFLAGS} ${CCOV} ${INCLUDES} -c Airline.cpp

Hotel.o: Hotel.cpp
	${CC} ${CFLAGS} ${CCOV} ${INCLUDES} -c Hotel.cpp


clean:
	echo "Cleaning....."
	rm *.o run *.gcov *.gcda *.gcno
