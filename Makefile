CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = 

SRCS = main.c clock.c
OBJS = $(SRCS:.c=.o)
TARGET = clock.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) 