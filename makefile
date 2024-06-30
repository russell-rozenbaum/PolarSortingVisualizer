CXX = g++
CXXFLAGS = -std=c++11 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = Insertion_Sort
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

.PHONY: clean

clean:
	rm -f $(TARGET)