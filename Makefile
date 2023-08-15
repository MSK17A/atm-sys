objects = src/main.o

main : $(objects)
	cc -o main $(objects) -l sqlite3

clean :
	rm -f $(objects)
	rm -f main
