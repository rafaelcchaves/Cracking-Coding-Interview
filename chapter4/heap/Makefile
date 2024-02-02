all: heap main
	g++ bin/main.o bin/heap.o -o bin/main 
heap:
	g++ -c src/heap.cpp -o bin/heap.o -Iinclude
main:
	g++ -c src/main.cpp -o bin/main.o -Iinclude
clean:
	rm bin/*
