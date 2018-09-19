################################################################################
#
# Makefile
#
# Builds the echod daemon
################################################################################
AR      := ar
CC      := gcc
CFLAGS  := -I./include -O3
WFLAGS	:= -Wall -Wextra -pedantic -std=iso9899:1990 -ansi
NAME	:= echo
DNAME	:= $(NAME)d
SHELL	:= /bin/sh
SRCDIR	:= src
INCDIR	:= include
SRC_DIRS:= $(SRCDIR)/
C_SRCS	:= $(notdir $(wildcard $(addsuffix *.c,$(SRC_DIRS))))
OBJECTS	:= $(patsubst %.c,%.o,$(C_SRCS))
VPATH	:= $(SRC_DIRS)

.PHONY: all
all: $(DNAME)

$(DNAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(WFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(WFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJECTS) $(DNAME) \
		*.a *.i *.o

