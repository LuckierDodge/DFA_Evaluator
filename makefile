# build dfa from dfa.cpp
all: dfa.cpp
	g++ -g -Wall -o dfa dfa.cpp

clean: 
	$(RM) dfa
