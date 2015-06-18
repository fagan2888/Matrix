#CPP Makefile

CXX:=g++
DBG:=-DDBG
CXXFLAGS:=-std=c++11 $(DBG)
LDFLAGS:=-lopenblas
OPTS:=-O2 

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

LIB:=/home/nashp/tools
LIBDIR:=-L${LIB}/lib -L../lib
INCLUDE:=-I${LIB}/include -I../include -I/home/nashp/Documents/Boost/1.56
