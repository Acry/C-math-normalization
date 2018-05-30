CC=gcc
CFLAGS=-Wall -Wextra -mtune=native
LDFLAGS  = -lm
srcdir	 =./
TARGETS	 = 1 2

.SUFFIXES:
.SUFFIXES: .c .o

.PHONY: all
all: $(TARGETS)

1: $(srcdir)main.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

2: $(srcdir)main2.c
	$(CC) $(CFLAGS) -o $@ $+ $(LDFLAGS)

.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true

