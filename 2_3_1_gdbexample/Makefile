CC=gcc
CFLAGS=-g3 -O0 -Wall
TARGET=example
SOURCE=example.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

debug: $(TARGET)
	gdb -tui $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: debug clean run