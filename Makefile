CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
TARGET   := atendimento
SRCS     := $(wildcard src/*.cpp)
OBJS     := $(SRCS:src/%.cpp=build/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: src/%.cpp | build
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

build:
	mkdir -p build

clean:
	rm -rf build $(TARGET) $(TARGET).exe

-include $(OBJS:.o=.d)

.PHONY: all clean
