TOP_DIR=$(shell pwd)
INCLUDE_PATH=-I$(TOP_DIR) -I$(DSA_DIR) -I$(ALGORITHM_DIR)
LIB_PATH=-L$(ALGORITHM_DIR) -L$(DSA_DIR)
LIB=-Wl,-Bdynamic -lalgorithm -ldsa
TARGET=dsacpp
SOURCE=$(TOP_DIR)/main.cc $(TOP_DIR)/src/*.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(INCLUDE_PATH) $(LIB_PATH) -g -o $@ $^ $(LIB)

.PHONY: clean
clean:
	-rm $(TARGET)
