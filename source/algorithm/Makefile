TOP_DIR=$(shell pwd)
INCLUDE_PATH=-I$(TOP_DIR) -I$(DSA_DIR)
LIB=-Wl,-Bdynamic -ldsa
LIB_PATH=-L$(DSA_DIR)
TARGET=libalgorithm.so
SOURCE=$(TOP_DIR)/src/*.cc

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(INCLUDE_PATH) $(LIB_PATH) -g -fPIC -shared -o $@ $^ $(LIB)

.PHONY: clean
clean:
	-rm $(TARGET)
