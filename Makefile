CC = cc 
CFLAGS = -Wall -Wextra
TARGET = cquotes
SRC = main.c
OBJS = $(SRC:.c=.o)

.SILENT:

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run