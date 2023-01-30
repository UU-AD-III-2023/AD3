CXX=g++
CXXFLAGS:=-Wall -Werror -Wextra -pedantic -std=c++17
RELEASEFLAGS:=-O3
DEBUGFLAGS:=-g

.PHONY: all clean
all: submission

submission: main.o
	$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -o InvDes $^

main.o: main.cc
	$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -c $^

clean:
	$(RM) *.o InvDes

debug: main.cc
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -D DEBUG -o InvDes main.cc