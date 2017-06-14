#CC=musl-gcc
CFLAGS=-static -Os -ansi -Wall -pedantic

all: src/ackermann src/einstein-e src/collatz

clean:
	rm -f src/ackermann src/einstein-e src/collatz

togit: clean
	git add .
	git commit -m "Updated from makefile"
	git push origin
