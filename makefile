# build dfa from dfa.cpp
all: dfa.cpp dfa.h
	gcc -g -Wall -o dfa dfa.cpp

clean: 
	$(RM) dfa
