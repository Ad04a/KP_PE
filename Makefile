TARGET_EXEC := KP_PE.exe

BUILD_DIR := ./Build
SOURCE_DIR := ./Source

FINAL_EXEC := $(BUILD_DIR)/$(TARGET_EXEC)

CXX := g++

CXXFLAGS := -Wall -pedantic -std=c++11

CPPFLAGS := -MMD

INCLUDE_DIRS := -I./Source/Public

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

all: $(FINAL_EXEC) run

build: $(FINAL_EXEC)

$(FINAL_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(FINAL_EXEC) 

-include $(DEPS)

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(CPPFLAGS) -c $< -o $@


run: $(FINAL_EXEC)
	$(FINAL_EXEC)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

