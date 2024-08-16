# compilator and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Werror -g
#LDLIBS=-ln

# targets
TARGET = game

# source files
SRCS = game.c math_game.c
HDRS = math_game.h

# object files
OBJS = $(SRCS:.c=.o)

# compilation of output files
$(TARGET): $(OBJS)
		$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# compilation of object files
%.o: %.c $(HDRS)
		$(CC) $(CFLAGS) -c $< -o $@

#clean files
.PHONY: clean
clean:
		rm -f $(OBJS) $(TARGET)
