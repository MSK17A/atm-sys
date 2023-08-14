objects = src/main.o

atm : $(objects)
	cc -o atm $(objects)

main.o : src/header.h

clean :
	rm -f $(objects)
