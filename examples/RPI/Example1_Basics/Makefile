.DEFAULT_GOAL :=Example1_Basics 
INCLUDE=../../../src ../../../src/driver
FLAGS = -DRPI -Wall -c

all: Example1_Basics


Example1_Basics: Example1_Basics.o libhscdtd008a.a
	g++ -o Example1_Basics Example1_Basics.o -L. -lhscdtd008a
	
libhscdtd008a.a: hscdtd008a.o hscdtd008a_driver.o transport.o platform_rpi.o
	 ar cvq libhscdtd008a.a hscdtd008a.o hscdtd008a_driver.o transport.o platform_rpi.o

Example1_Basics.o: Example1_Basics.cpp 
	g++ $(FLAGS) -I$(INCLUDE)  -o Example1_Basics.o Example1_Basics.cpp

hscdtd008a.o: ../../../src/hscdtd008a.cpp
	g++ $(FLAGS) -I$(INCLUDE)  -o hscdtd008a.o ../../../src/hscdtd008a.cpp

hscdtd008a_driver.o: ../../../src/driver/hscdtd008a_driver.c
	gcc $(FLAGS) -I$(INCLUDE)  -o hscdtd008a_driver.o ../../../src/driver/hscdtd008a_driver.c

transport.o: ../../../src/driver/transport.c
	gcc $(FLAGS) -I$(INCLUDE)  -o transport.o ../../../src/driver/transport.c

platform_rpi.o: ../../../src/driver/platform_rpi.cpp
	g++ $(FLAGS) -I$(INCLUDE)  -o  platform_rpi.o ../../../src/driver/platform_rpi.cpp

clean:
	rm -f *.o Example1_Basics  *.a
