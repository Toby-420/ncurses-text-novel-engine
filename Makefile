NAME		:= engine
VERSION		?= dev

CC		:= gcc
FLAGS		:= -Wall
LDFLAGS		:= -lncurses


BUILD		:= bin

SRC		:= src/*.c

BIN		:= $(BUILD)/$(NAME)

.PHONY: all

#------------------------------------------------------------

all: $(SRC) | $(BUILD)
	$(CC) $(SRC) $(FLAGS) $(LDFLAGS) -o $(BIN)
	strip $(BIN)

$(BUILD):
	mkdir -p $@

#------------------------------------------------------------
clean:
	rm -rf  $(BUILD)
