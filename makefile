CC = g++ -std=c++11 -Wall -Wextra -I.

all: fqueue.x in2post.x

fqueue.x: tqueue.h fqueue.cpp
	$(CC) -o fqueue.x fqueue.cpp

in2post.x: tqueue.h tstack.h in2post.cpp
	$(CC) -o in2post.x in2post.cpp
