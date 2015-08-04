#CPP Makefile

CXX:=g++
DBG:=-g#-DDBG
CXXFLAGS:=-std=c++11 -U__STRICT_ANSI__ $(DBG)
LDFLAGS:=-lopenblas
OPTS:=-O2 

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

BLASLIB:=/home/nashp/tools
BOOSTLIB:=/home/nashp/Documents/Boost/1.56
LIBDIR:=-L${BLASLIB}/lib -L/home/nashp/Matrix/lib
INCLUDE:=-I${BLASLIB}/include -I../include -I$(BOOSTLIB)
