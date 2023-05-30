# CC = g++
# CFLAGS = -Wall

# CPP_SRC_FILES = $(wildcard src/*.cpp)

# HEADER_FILES=$(wildcard include/*.h)

# OBJ_FILES=$(patsubst src/%.cpp,obj/%.o,$(CPP_SRC_FILES))

# TARGET = register.x

# all: create_dir $(CPP_SRC_FILES) $(HEADER_FILES) $(OBJ_FILES)
# 	$(CC) $(OBJ_FILES) -o $(TARGET)

# obj/%.o: src/%.cpp
# 	$(CC) $(CFLAGS) -I ./include -c $^ -o $@

# create_dir:
# 	mkdir -p obj

# clear:
# 	rm -f *.x
# 	rm -f -r obj/

CC = g++
CFLAGS = -Wall

CPP_SRC_FILES = $(wildcard src/*.cpp)
HEADER_FILES = $(wildcard include/*.h)
OBJ_FILES = $(patsubst src/%.cpp,obj/%.o,$(CPP_SRC_FILES))

TARGET = register.x

all: create_dir $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -I ./include -c $^ -o $@

create_dir:
	mkdir -p obj

clear:
	rm -f *.x
	rm -f -r obj/

