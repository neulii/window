OBJS = main.o window.o

CXXFLAGS = -Wall -std=c++11 `wx-config --cxxflags`
LDLIBS   = `wx-config --libs`

window: $(OBJS)
	g++ -o window  $(OBJS) $(CXXFLAGS) $(LDLIBS)  

window.o: window.cpp window.h
	g++ -c window.cpp $(CXXFLAGS)

main.o: main.cpp main.h
	g++ -c main.cpp $(CXXFLAGS)

clean:

	rm $(OBJS)
	rm window
