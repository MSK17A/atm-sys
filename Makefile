SRCDIR = src
OBJDIR = obj
LDFLAGS = -l sqlite3 -lncurses
CFLAGS = -Wall -Wextra -Werror

SOURCES = $(wildcard $(SRCDIR)/*.c) # All Source files in /src directory
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES)) # Replace files names ends in .c inside /src to end in .o
EXECUTABLE = main.out

# Compile sources to objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	cc -g $(CFLAGS) -I headers -c -g $< -o $@

# Compile main.c
$(EXECUTABLE): $(OBJECTS) main.c
	cc -g -I headers $^ -o $@ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)