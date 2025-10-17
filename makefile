CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS =
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = main_app
.PHONY: all clean
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)	

.PHONY: all clean
