
GCC= gcc
CFLAGS= -Wall -Wextra -Wpedantic -Wshadow
#LDFLAGS= -lpthread

SRCS := $(wildcard *.c)
EXECS := $(SRCS:%.c=%)

all: ${EXECS}

%: %.o
	${GCC} ${LDFLAGS} $< -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	rm -rvf *.o ${EXECS}


