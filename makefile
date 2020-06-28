redbeard: redbeard.o setup.o utilities.o
	gcc -o redbeard redbeard.o setup.o utilities.o
	
redbeard.o: redbeard.c redbeard.h
	gcc -c -ansi -pedantic -Wall redbeard.c
	
setup.o: setup.c setup.h
	gcc -c -ansi -pedantic -Wall setup.c

utilities.o: utilities.c utilities.h
	gcc -c -ansi -pedantic -Wall utilities.c
