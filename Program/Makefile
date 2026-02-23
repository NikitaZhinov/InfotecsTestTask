CC =g++ -Wall -std=c++17 -I./inc -I../JournalLib/inc

TARGET =program.out

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, src/%.o, $(SRC))

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $^ -o $@ -ljournal -L../JournalLib

src/%.o : src/%.cpp
	$(CC) -c $< -o $@

test :

clean :
	rm -rf src/*.o test/*.o *.out *.test

run :
	@LD_LIBRARY_PATH=../JournalLib ./$(TARGET)
