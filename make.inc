#CPP Makefile Joshi Cpp

CXX:=g++-4.8
DBG:=#-DDBG
CXXFLAGS:=-fPIC -std=c++11 $(DBG)
LDFLAGS:=-shared
OPTS:=-O2

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

LIB:=
LIBDIR:=

