TOP_DIR = $(shell pwd)
DSA_DIR = $(DSA_DIR)
TARGET = libalgorithm.so
SOURCE = $(TOP_DIR)/src/*.c $(TOP_DIR)/problems/*.c

$(TARGET): $(SOURCE)
	$(CXX) -I$(DSA_DIR) -L$(DSA_DIR) -ldsa -fPIC -shared -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)
