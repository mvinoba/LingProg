CXX = g++
CXXFLAGS = `perl -MExtUtils::Embed -e ccopts -e ldopts` -Wall

main: main.o menu.o
	$(CXX) $(CXXFLAGS) -o main main.o menu.o

main.o: main.cpp menu.h
	$(CXX) $(CXXFLAGS) -c main.cpp

menu.o: menu.h

