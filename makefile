CC=gcc
AR=ar
FLAGS= -Wall -g

mains: main.o libmyBank.a
	$(CC) $(FLAGS) -o mains main.o libmyBank.a
	
libmyBank.a: myBank.o
	$(AR) -rcs libmyBank.a myBank.o 
	
main.o: main.c myBank.h
	$(CC) $(FLAGS) -c $< -o $@
	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c $< -o $@
	
.PHONY: clean libmyBank.a mains

clean:
	rm *.o *.a mains 
	
