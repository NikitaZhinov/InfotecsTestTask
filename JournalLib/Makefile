CC =g++ -Wall -std=c++17 -I./inc

TARGET =libjournal.so
TARGET_TEST =journal-test.out

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, src/%.o, $(SRC))

SRC_TEST = $(wildcard test/*.cpp)
OBJ_TEST = $(patsubst test/%.cpp, test/%.o, $(SRC_TEST))

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $^ -shared -o $@

src/%.o : src/%.cpp
	$(CC) -fpic -c $< -o $@

test : $(TARGET_TEST)
	LD_LIBRARY_PATH=. ./$(TARGET_TEST)

$(TARGET_TEST) : $(OBJ_TEST) $(TARGET)
	$(CC) $^ -o $@ -lgtest

test/%.o : test/%.cpp
	$(CC) -c $< -o $@

clean :
	rm -rf src/*.o test/*.o *.so *.out *.test
