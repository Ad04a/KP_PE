TARGET_EXEC := KP_PE.exe

BUILD_DIR := ./Build
SOURCE_DIR := ./Source

FINAL_EXEC := $(BUILD_DIR)/$(TARGET_EXEC)

CXX := g++

CXXFLAGS := -Wall -pedantic -std=c++11


SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)

all: $(FINAL_EXEC) run

build: $(FINAL_EXEC)

-include $(DEPENDS)

$(FINAL_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(FINAL_EXEC) 

# Build step for C++ source
$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@


run: $(FINAL_EXEC)
	$(FINAL_EXEC)

.PHONY: clean
clean:
	rmdir -r $(BUILD_DIR)