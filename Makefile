# Makefile for f2022, ecs36b
#

CC = g++ -std=c++14

# CFLAGS = -g -I/usr/include/jsoncpp

CFLAGS = -g 

INC	=	ecs36b_Common.h

LDFLAGS = 	-L/usr/local/Cellar/jsoncpp/1.9.5/include/ -ljsoncpp
#-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp

# rules.
all: 	hw3

#
#

Location.o:		Location.cpp Location.h
	$(CC) -c $(CFLAGS) Location.cpp

Time.o:	Time.cpp Time.h
	$(CC) -c $(CFLAGS) Time.cpp

Person.o:	Person.cpp Person.h
	$(CC) -c $(CFLAGS) Person.cpp

Thing.o:	Thing.cpp Thing.h
	$(CC) -c $(CFLAGS) Thing.cpp

Record.o:	Record.cpp Record.h
	$(CC) -c $(CFLAGS) Record.cpp

hw3.o:	hw3.cpp Person.h Record.h Thing.h Location.h Time.h JvTime.h
	$(CC) -c $(CFLAGS) hw3.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

hw3:		hw3.o Person.o Record.o Thing.o Location.o Time.o JvTime.o
	g++ -std=c++14 hw3.o Person.o Record.o Thing.o Location.o Time.o JvTime.o -o hw3 $(LDFLAGS)
# add relevant .o files
clean:
	rm -f *.o *~ core hw3

