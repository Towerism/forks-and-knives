EXECUTABLE := forks-and-knives
CXXFLAGS ?= -std=c++11

all: $(EXECUTABLE)

$(EXECUTABLE): main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

.PHONY: all clean
