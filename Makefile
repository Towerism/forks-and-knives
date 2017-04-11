EXECUTABLE := forks-and-knives

all: $(EXECUTABLE)

$(EXECUTABLE): main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp) -o $@

%.cpp:
	$(CXX) $(CXXFLAGS) -o $@

clean:
	rm -rf *.o $(EXECUTABLE)

.PHONY: all clean
