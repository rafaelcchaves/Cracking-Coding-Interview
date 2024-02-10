all: node tree main 
	g++ bin/node.o bin/tree.o bin/main.o -o bin/main
node:
	g++ -c src/node.cpp -o bin/node.o -Iinclude
tree:
	g++ -c src/tree.cpp -o bin/tree.o -Iinclude
main:
	g++ -c src/main.cpp -o bin/main.o -Iinclude

