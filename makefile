CC = g++ -O3 -std=c++1y
CFLAGS  = -g -Wall 
SQLFLAGS=-lmysqlcppconn
OPENMP= -fopenmp
WP=-lwiringPi 

default:main

main: Aux.o SQLCon.o main.o FFT.o DCT.o DWT.o FCT.o I2C.o SPI.o
	$(CC) $(CFLAGS) $(SQLFLAGS) $(OPENMP) $(WP) -o main Aux.o SQLCon.o main.o FFT.o DCT.o DWT.o FCT.o I2C.o SPI.o

FFT.o: FFT.cpp FFT.hpp
	$(CC) $(CFLAGS) -c FFT.cpp 

DCT.o: DCT.cpp DCT.hpp
	$(CC) $(CFLAGS) $(OPENMP) -c DCT.cpp 

DWT.o: DWT.cpp DWT.hpp
	$(CC) $(CFLAGS) -c DWT.cpp 

FCT.o: FCT.cpp FCT.hpp
	$(CC) $(CFLAGS) -c FCT.cpp 

SQLCon.o:SQLCon.cpp SQLCon.hpp
	$(CC) $(CFLAGS) -c SQLCon.cpp 

Aux.o: Aux.cpp Aux.hpp
	$(CC) $(CFLAGS) -c Aux.cpp

I2C.o: I2C.cpp I2C.hpp
	$(CC) $(CFLAGS) $(WP) -c I2C.cpp

SPI.o: SPI.cpp SPI.hpp
	$(CC) $(CFLAGS) $(WP) -c SPI.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) $(WP) -c main.cpp


clean:
	$(RM) count *.o *~ main

