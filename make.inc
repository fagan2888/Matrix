#CPP Makefile Joshi Cpp

CXX:=g++
DBG:=#-DDBG
CXXFLAGS:=-std=c++11 $(DBG)
LDFLAGS:=-lopenblas
OPTS:=-O2

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

LIB:=/opt/numerical
LIBDIR:=-L${LIB}/lib -L../lib
INCLUDE:=-I${LIB}/include -I../include
