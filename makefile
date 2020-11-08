CC=g++
PROJ_DIR := ~/ML
SRC_DIR := $(PROJ_DIR)/src
INCLUDE_DIR := $(PROJ_DIR)/include
CFLAGS := -std=c++17 -O2 -Wall

all: $(SRC_DIR)/data.cpp $(SRC_DIR)/data_handler.cpp $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o main $(SRC_DIR)/*.cpp
