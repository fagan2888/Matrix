#CPP Makefile Joshi Cpp

CXX:=g++-4.9
DBG:=#-DDBG
CXXFLAGS:=-fPIC -std=c++11 $(DBG)
LDFLAGS:=-lopenblas -lMatrix
OPTS:=-O2

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

LIB:=
LIBDIR:=-L/opt/numerical/lib -L../lib
INCLUDE:=-I/opt/numerical/include -I../include
