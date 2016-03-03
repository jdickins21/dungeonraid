CXX=g++

SRCS=$(wildcard *.cpp)
OBJECTS=$(SRCS:.cpp=.o)
CXXFLAGS=$(shell sdl2-config --cflags)
LIBS=$(shell sdl2-config --libs) -lSDL2_image

all: dungeon_raid

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -g -O2 -std=c++11 $<

dungeon_raid: $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LIBS)

clean: 
	$(RM) main $(OBJECTS)