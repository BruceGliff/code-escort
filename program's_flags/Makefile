CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=
SOURCES=main.cc errorDumper.cc  flagsChecker.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=program.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@


clean: 
	rm *.o *.out
