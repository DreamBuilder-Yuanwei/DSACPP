TOP_DIR=$(shell pwd)
INCLUDE_PATH=-I$(TOP_DIR)
TARGET=libdsa.so
SOURCE=$(TOP_DIR)/src/*.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(INCLUDE_PATH) -g -fPIC -shared -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)
