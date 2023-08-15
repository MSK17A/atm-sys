objects = src/main.o

main : $(objects)
	cc -o main $(objects) -lsqlite3

clean :
	rm -f $(objects)
	rm -f main
