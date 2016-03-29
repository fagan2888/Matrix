#CPP Makefile

CXX:=g++
DBG:=-g -DDBG
CXXFLAGS:=-std=c++11 $(DBG)
LDFLAGS:=-lgpu_matrix -lopenblas
OPTS:=-O2 

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

BLASLIB:=/opt/libraries/numerical
BOOSTLIB:=/opt/libraries/Boost/1.58
LIBDIR:=-L${BLASLIB}/lib -L../lib
INCLUDE:=-I${BLASLIB}/include -I../include -I$(BOOSTLIB)/include
