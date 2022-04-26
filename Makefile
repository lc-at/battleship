CC = clang++
TARGET = battleship
ODIR = obj
CFLAGS = -Wall -Wextra -std=c++17
OBJECTS = $(patsubst %.cpp, $(ODIR)/%.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h);

.PHONY: default all clean

default: all

all: $(TARGET)

$(ODIR)/%.o: %.cpp $(HEADERS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJECTS)
