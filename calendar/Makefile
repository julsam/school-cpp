.SUFFIXES:

TARGET = bin
OBJ = clientAgenda.o evenement.o
CXX = g++
CXXFLAGS = -W -Wall -g
#LDFLAGS =


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
