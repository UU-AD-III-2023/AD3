CXX=g++
CXXFLAGS:=-Wall -Werror -Wextra -pedantic -std=c++17
RELEASEFLAGS:=-O3
DEBUGFLAGS:=-g

.PHONY: all clean
all: submission

submission: LocalSearch.o Design.o DotProduct.o Move.o Tabu.o Cost.o InvDes.o 
	$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -o InvDes $^

main.o: LocalSearch.cpp Design.cpp DotProduct.cpp Move.cpp Tabu.cpp Cost.cpp InvDes.cc
	$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -c $^

clean:
	$(RM) *.o InvDes

debug: InvDes.cc
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -D DEBUG -o InvDes InvDes.cc