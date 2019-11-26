OBJS = main.o window.o

CXXFLAGS = -Wall -std=c++11 `wx-config --cxxflags --libs`

window: $(OBJS)
	g++ -o window  main.o window.o $(CXXFLAGS)

window.o: window.cpp window.h
	g++ -c window.cpp -o window.o $(CXXFLAGS)

main.o: main.cpp main.h
	g++ -c main.cpp -o main.o $(CXXFLAGS)

clean:

	rm $(OBJS)
	rm window
