CC = gcc
CFLAGS = -Wall -Werror -g --coverage
LDFLAGS = --coverage

TARGET = convert
CTEST = ctest

SRCS = main.c convert.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(LDFLAGS)

ctest: $(OBJS)
	$(CC) $(CFLAGS) -o $(CTEST) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET) $(CTEST) *.gcda *.gcno *.gcov

.PHONY: all clean

