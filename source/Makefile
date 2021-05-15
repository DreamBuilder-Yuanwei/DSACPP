TOP_DIR = $(shell pwd)
export DSA_DIR = $(TOP_DIR)/dsa
UNITTEST_DIR = $(TOP_DIR)/unittest
export ALGORITHM_DIR = $(TOP_DIR)/algorithm

.PHONY: all clean

all:
	@echo "make libalgorithm.so start!"
	$(MAKE) -C $(ALGORITHM_DIR) all
	@echo "make libalgorithm.so end!"

	@echo "make dsacpp start!"
	$(MAKE) -C $(UNITTEST_DIR) all
	@echo "make dsacpp end!"

clean:
	@echo "make clean start!"
	$(MAKE) -C $(ALGORITHM_DIR) clean
	$(MAKE) -C $(UNITTEST_DIR) clean
	@echo "make clean end!"
