TOP_DIR=$(shell pwd)
INCLUDE_PATH=-I$(TOP_DIR) -I$(ALGORITHM_DIR)
TARGET=libdsa.so
SOURCE=$(TOP_DIR)/src/*.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(INCLUDE_PATH) -fPIC -shared -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)
