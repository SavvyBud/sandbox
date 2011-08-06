TARGET=mysort

SRCS=main.c insertsort.c mergesort.c
HDRS=main.h insertsort.h mergesort.h
OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAGS=-g -Wall 

all: $(SRCS) ${TARGET}

${TARGET}: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf *.o ${TARGET}
	
.c.o:
	$(CC) $(CFLAGS) $< -c -o $@
