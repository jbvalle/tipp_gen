CC=gcc

IDIR=../include

CFLAGS=-g -Wall -Wextra -pedantic -O0

TARGET=tippgen

SRCS=$(wildcard *.c)

BINS=$(SRCS: %.c=%)

all: $(TARGET) run


$(TARGET): $(SRCS)
	@$(CC) $(CFLAGS) -o $@ $^ -lm -I$(IDIR)

segfault: $(SRCS)
	ulimit -c unlimited
	$(CC) $(CFLAGS) -o $(TARGET) $^ -lm -I$(IDIR)
	gdb $(TARGET) core

debug: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $^ -lm -I$(IDIR)
	gdb $(TARGET) 

memleak:
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

run:
	@cat ../README.txt

help:
	@cat Makefile

clean:
	rm -rf *.o .*swp .*swo $(BINS)

