CC=g++
CFLAGS=-c -Wall -std=c++17
LDFLAGS=
SOURCES=main.cc ErrorProducer.cc FileProducer.cc FlagsChecker.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=program.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cc.o:
	$(CC) $(CFLAGS) $< -o $@


clean: 
	rm *.o *.out
