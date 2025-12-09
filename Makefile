.PHONY: all clean debug

CC = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
TARGET = BF_Interpreter

all: $(TARGET)
debug: CXXFLAGS += -g -O0
debug: clean $(TARGET)
$(TARGET): *.cpp
	$(CC) $(CXXFLAGS) -o $(TARGET) *.cpp
clean:
	rm -f $(TARGET)