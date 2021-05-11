TOP_DIR=$(shell pwd)
INCLUDE_PATH=-I$(TOP_DIR) -I$(DSA_DIR)
LIB_PATH=-L$(DSA_DIR)
LIB=-ldsa
TARGET=libalgorithm.so
SOURCE=$(TOP_DIR)/src/*.cc $(TOP_DIR)/problems/*.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(INCLUDE_PATH) $(LIB_PATH) $(LIB) -fPIC -shared -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)
