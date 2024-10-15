CC=gcc 
FLAGS= -Wall -g


all:	solution solutionBetter


solutionBetter:	solutionBetter.o 
	$(CC) solutionBetter.c -o solutionBetter -lpthread
	
	
solutionBetter.o:	solutionBetter.c 
	$(CC) $(FLAGS) -c solutionBetter.c


solution:	solution.o 
	$(CC) solution.c -o solution -lpthread
	
	
solution.o:	solution.c 
	$(CC) $(FLAGS) -c solution.c


.PHONY: clean all

clean: 
	rm -f *.o solution solutionBetter


