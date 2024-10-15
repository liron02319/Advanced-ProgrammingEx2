# Advanced Programming Course Assignment 2

Name : Liron cohen

## Description
In our assinment we will use a random number generator (provided) that simulates the endless stream,
and your task is to count the number of prime numbers in this stream.
The idea is to parallelize the process, so all the cpu core are utilized.

# Building all the necessary files & the main program.
run at shell the command :
make all


## Running Time

when i run the file "primeCounter" file it took 54.106sec
when i run the file "solution" without improving the isPrime function it took 12.969sec( 4 times! ) from file primeCounter
when i run the file "solution" with improving the isPrime function it took 4.991sec( 10 times !) from file primeCounter
the size is below 2MB

## file ScreenPicture 
there are pictures of the running time from up
and the size that below 2MB

## Run At Shell
```
# Run the shell.

there are 2 files : solution and solutionBetter

without improving the isPrime function (90% mark)
run the command :

time ./randomGenerator 10 10000000 | ./solution



with improving the isPrime function (10% mark)
run the command :

time ./randomGenerator 10 10000000 | ./solutionBetter






