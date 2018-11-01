# build dfa from dfa.cpp
all: dfa.cpp
	gcc -g -Wall -o dfa dfa.cpp

clean: 
	$(RM) dfa
