TOP_DIR = $(shell pwd)
DSA_DIR = $(TOP_DIR)/dsa
UNITTEST_DIR = $(TOP_DIR)/unittest
ALGORITHM_DIR = $(TOP_DIR)/algorithm

.PHONY: all clean

all:
	@echo "make libdsa.so start!"
	$(MAKE) -C $(DSA_DIR) all
	@echo "make libdsa.so end!"

	@echo "make libalgorithm.so start!"
	$(MAKE) -C $(ALGORITHM_DIR) all $(DSA_DIR)
	@echo "make libalgorithm.so end!"

	@echo "make dsacpp start!"
	$(MAKE) -C $(UNITTEST_DIR) all $(DSA_DIR) $(ALGORITHM_DIR)
	@echo "make dsacpp end!"

clean:
	@echo "make clean start!"
	$(MAKE) -C $(DSA_DIR) clean
	$(MAKE) -C $(ALGORITHM_DIR) clean
	$(MAKE) -C $(UNITTEST_DIR) clean
	@echo "make clean end!"