SRCDIR = src
OBJDIR = obj
LDFLAGS = -l sqlite3

SOURCES = $(wildcard $(SRCDIR)/*.c) # All Source files in /src directory
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES)) # Replace files names ends in .c inside /src to end in .o
EXECUTABLE = main

# Compile sources to objects
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	cc -Iheaders -c $< -o $@

# Compile main.c
$(EXECUTABLE): $(OBJECTS) main.c
	cc -Iheaders $^ -o $@ $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJDIR)/*.o $(EXECUTABLE)