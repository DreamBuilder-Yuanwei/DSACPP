TOP_DIR=$(shell pwd)
INCLUDE_PATH=-I$(TOP_DIR) -I$(DSA_DIR) -I$(ALGORITHM_DIR)
LIB_PATH=-L$(DSA_DIR) -L$(ALGORITHM_DIR)
LIB=-ldsa -lalgorithm
TARGET=dsacpp
SOURCE=$(TOP_DIR)/src/*.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(INCLUDE_PATH) $(LIB_PATH) $(LIB) -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)
