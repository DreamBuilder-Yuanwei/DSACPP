TOP_DIR = $(shell pwd)
DSA_DIR = $(DSA_DIR)
ALGORITHM_DIR = $(ALGORITHM_DIR)
TARGET = dsacpp
SOURCE = $(TOP_DIR)/src/*.c

$(TARGET): $(SOURCE)
	$(CXX) -I$(DSA_DIR) -I$(ALGORITHM_DIR) -L$(DSA_DIR) -L$(ALGORITHM_DIR) -ldsa -lalgorithm -o $@ $^

.PHONY: clean
clean:
	-rm $(TARGET)