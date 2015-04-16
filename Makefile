all: main.o functions.o
	$(CC) -o main main.o functions.o

run:
	./main

clean:
	rm -f main test *.o *.obj *.lst

test: test.o functions.o
	$(CC) -o test test.o functions.o
	./test
	rm -f test