#CPP Makefile

CXX:=g++
DBG:=-g -DDBG
CXXFLAGS:=-std=c++14 $(DBG)
LDFLAGS:=-lgpu_matrix -lopenblas
OPTS:=-O0 

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

BLASLIB:=/opt/libraries/numerical
BOOSTLIB:=/opt/libraries/boost/1.60
LIBDIR:=-L${BLASLIB}/lib -L../lib
INCLUDE:=-I${BLASLIB}/include -I../include -I$(BOOSTLIB)/include
