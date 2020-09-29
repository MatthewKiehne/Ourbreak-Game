CC = g++
CFLAGS = -std=c++11

all: main.o City.o MedicalExecutive.o
	$(CC) $(CFLAGS) main.o City.o MedicalExecutive.o -o outbreak
	
main.o: main.cpp City.h MedicalExecutive.h
	$(CC) $(CFLAGS) main.cpp -c
	
City.o: City.cpp City.h
	$(CC) $(CFLAGS) City.cpp -cpp -c
	
MedicalExecutive.o: MedicalExecutive.cpp City.h
	$(CC) $(CFLAGS) MedicalExecutive.cpp -c
	
clean:
	rm -f *.o *.*~ a.out