#testt : testManipGraph.o manipGraph.o
#	gcc testManipGraph.o manipGraph.o -o testt

testInput : Input.o
	gcc Input.o -o testInput

#manipGraph.o : manipGraph.c manipGraph.h
#	gcc -std=c99 -c manipGraph.c

#testManipGraph.o : testManipGraph.c manipGraph.h
#	gcc -std=c99 -c testManipGraph.c

Input.o : Input.c
	gcc -std=c99 -c Input.c

.PHONY : clean runTest
clean :
	rm *Graph.o 
runTest :
	./testInput




