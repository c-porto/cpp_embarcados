TARGET=machine


CXX=~/Downloads/sparc-elf-3.4.4/bin/sparc-elf-g++
CFLAGS=-I.

.PHONY: all
all: 
	$(CXX) $(CFLAGS) ./*.cpp -o $(TARGET)

.PHONY: clean
clean:
	rm ./$(TARGET)
