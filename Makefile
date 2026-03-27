CC = gcc
CFLAGS = -Wall -Wextra -o

TARGET = run
SRC = main.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) day_end_summary.txt