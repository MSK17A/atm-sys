objects = src/main.o

main : $(objects)
	cc -o main $(objects)

clean :
	rm -f $(objects)
	rm -f main
