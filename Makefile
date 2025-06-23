CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC_DIR = src
OBJ_DIR = obj
BIN = pierogi

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -g -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -g -lm

clean:
	rm -rf $(OBJ_DIR) $(BIN)

.PHONY: all clean
