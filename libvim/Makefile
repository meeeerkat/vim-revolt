CC = g++
AR = ar

# -O0 option to activate optimisations
CFLAGS = -Wall -Wextra -O0 -Iinclude `pkg-config --cflags glib-2.0`

SRC_FILES := $(shell find src -regextype sed -regex ".*\.cpp" -type f)
OBJ_FILES=$(patsubst src/%.cpp,obj/%.o,$(SRC_FILES))

LIB_FILE=libvim.a

all: $(LIB_FILE)

$(LIB_FILE): $(OBJ_FILES)
	$(AR) rsv $@ $^

$(OBJ_FILES): obj/%.o : src/%.cpp include/%.hpp
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf main $(OBJ_FILES) $(LIB_FILE)
