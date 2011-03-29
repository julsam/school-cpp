.SUFFIXES:

TARGET = bin
OBJ = main.o Duration.o
CXX = g++
#LDFLAGS =
DEBUG = yes

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $^ -o $(TARGET) $(CXXFLAGS)
	
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

.PHONY: clean, mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(TARGET)
