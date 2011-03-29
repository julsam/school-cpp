.SUFFIXES:

TARGET = bin
OBJ = main.o Peano.o
CXX = g++
#LDFLAGS =
DEBUG = yes

ifeq ($(DEBUG), yes)
	CXXFLAGS = -g -W -Wall
else
	CXXFLAGS = 
endif

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
