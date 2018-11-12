TARGET=devio
CFLAGS=-Wall

.PHONY: all clean

all: $(TARGET)

$(TARGET):

clean:
	rm -f $(TARGET)
