BINARY = test
OBJECTS = test.o mystring.o
HEADERS = mystring.h

CC = gcc
CXX = g++
CFLAGS = -std=c11  -g
CXXFLAGS = -std=c++11  -g
LDFLAGS = -g

.PHONY: all clean

all: $(BINARY)

clean:
	rm -f $(BINARY) $(OBJECTS)

$(BINARY): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@