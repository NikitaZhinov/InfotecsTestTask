CC =g++ -Wall -std=c++17 -I./inc -I../JournalLib/inc

TARGET =bin/program.out

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, bin/%.o, $(SRC))

all : check $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $^ -o $@ -ljournal -L../JournalLib/bin

bin/%.o : src/%.cpp
	$(CC) -c $< -o $@

test : all

docs :
	doxygen

clean :
	rm -rf *.test bin

rebuild : clean all

run : $(TARGET)
	@LD_LIBRARY_PATH=../JournalLib/bin ./$(TARGET)

check :
	@if [ ! -d "bin" ]; then mkdir bin; fi
