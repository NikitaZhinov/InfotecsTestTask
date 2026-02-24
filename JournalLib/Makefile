CC =g++ -Wall -std=c++17 -I./inc

TARGET =bin/libjournal.so
TARGET_TEST =bin/journal-test.out

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, bin/src-%.o, $(SRC))

SRC_TEST = $(wildcard test/*.cpp)
OBJ_TEST = $(patsubst test/%.cpp, bin/test-%.o, $(SRC_TEST))

all : check $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $^ -shared -o $@

bin/src-%.o : src/%.cpp
	$(CC) -fpic -c $< -o $@

test : check $(TARGET_TEST)
	@LD_LIBRARY_PATH=./bin ./$(TARGET_TEST)

$(TARGET_TEST) : $(OBJ_TEST) $(TARGET)
	$(CC) $^ -o $@ -lgtest

bin/test-%.o : test/%.cpp
	$(CC) -c $< -o $@

clean :
	rm -rf *.test bin

check :
	@if [ ! -d "bin" ]; then mkdir bin; fi

rebuild : clean all

docs : 
	doxygen
