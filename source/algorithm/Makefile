TOP_DIR=$(shell pwd)
INCLUDE_PATH=-I$(TOP_DIR) -I$(DSA_DIR)
TARGET=libalgorithm.so
SOURCE=$(TOP_DIR)/src/*.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(INCLUDE_PATH) -fPIC -shared -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)
