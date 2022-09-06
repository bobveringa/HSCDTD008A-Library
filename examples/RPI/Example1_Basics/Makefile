.DEFAULT_GOAL :=Example1_Basic 
INCLUDE=../../../src ../../../src/driver

Example1_Basic: Example1_Basics.o hscdtd008a.o hscdtd008a_driver.o transport.o platform_rpi.o
	g++ -o Example1_Basics Example1_Basics.o hscdtd008a.o hscdtd008a_driver.o transport.o platform_rpi.o

Example1_Basics.o: Example1_Basics.cpp 
	g++ -I$(INCLUDE) -c -o Example1_Basics.o Example1_Basics.cpp

hscdtd008a.o: ../../../src/hscdtd008a.cpp
	g++ -I$(INCLUDE) -c -o hscdtd008a.o ../../../src/hscdtd008a.cpp

hscdtd008a_driver.o: ../../../src/driver/hscdtd008a_driver.c
	gcc -I$(INCLUDE) -c -o hscdtd008a_driver.o ../../../src/driver/hscdtd008a_driver.c

transport.o: ../../../src/driver/transport.c
	gcc -I$(INCLUDE) -c -o transport.o ../../../src/driver/transport.c

platform_rpi.o: ../../../src/driver/platform_rpi.cpp
	g++ -I$(INCLUDE) -c -o  platform_rpi.o ../../../src/driver/platform_rpi.cpp

clean:
	rm -f *.o Example1_Basic 
