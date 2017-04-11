EXECUTABLE := forks-and-knives

all: $(EXECUTABLE)
CXXFLAGS ?= -std=c++11

$(EXECUTABLE): main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

.PHONY: all clean
