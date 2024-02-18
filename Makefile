all:	encript decript

encript: enc
	g++ -o enc enc.cpp
decript: dec
	g++ -o dec dec.cpp

