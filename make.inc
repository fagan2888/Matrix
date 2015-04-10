#CPP Makefile Joshi Cpp

CXX:=g++
DBG:=#-DDBG
CXXFLAGS:=-std=c++11 $(DBG)
LDFLAGS:=-lopenblas
OPTS:=-O2

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

LIB:=
LIBDIR:=-L/home/nashp/tools/lib -L../lib
INCLUDE:=-I/home/nashp/tools/include -I../include
