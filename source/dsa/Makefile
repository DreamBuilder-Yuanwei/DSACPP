TOP_DIR = $(shell pwd)
TARGET = libdsa.so
SOURCE = $(TOP_DIR)/src/*.c

$(TARGET): $(SOURCE)
	$(CXX) -fPIC -shared -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)
