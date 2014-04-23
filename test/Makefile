include ../make.inc

TARGET:=../bin/testing

LIB:=-lMatrix
LIBDIR:=-L../lib
INCLUDE:=-I../include

SRC_CXX:=main.cpp
OBJS_CXX:=$(patsubst %.cpp,%.cpp.o,$(SRC_CXX))
OBJS:=$(OBJS_CXX)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $< $(LIBDIR) $(LIB)

$(OBJS): $(SRC_CXX)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

