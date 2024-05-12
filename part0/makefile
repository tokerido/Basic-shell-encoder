#format is target-name: target dependencies 

 

#{-tab-}actions 

 # All Targets 

all: main 

 # Tool invocations 

# Executable "main" depends on the file main.o numbers.o add.o. 

main: main.o numbers.o add.o

	gcc -g -m32 -Wall -o main main.o numbers.o add.o
	
 # Depends on the source and header files 

main.o: main.c

	gcc -m32 -g -Wall -c -o main.o main.c 

numbers.o: numbers.c

	gcc -m32 -g -Wall -c -o numbers.o numbers.c 

add.o: add.s

	nasm -g -f elf -w+all -o add.o add.s 


 #tell make that "clean" is not a file name! 

.PHONY: clean 

 #Clean the build directory 

clean:

	rm -f *.o main