CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main
HSHDIR = hash

SRCS = main.cpp \
		$(HSHDIR)/hash.cpp \

EXECUTABLE = a.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

.PHONY: all run clean