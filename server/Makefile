CC = gcc
CFLAGS = -Wall -pthread

SRC = server.c http_handler.c logger.c
OBJ_DIR = obj
BIN_DIR = bin
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC = $(BIN_DIR)/server

all: $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
