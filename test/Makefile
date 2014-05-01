include ../make.inc

ADD:=add
GETSET:=getset
LIB:=-lMatrix
LIBDIR:=-L../lib
INCLUDE:=-I../include
LDFLAGS:=
SRC_CXX:=getsetelements.cpp
OBJS_CXX:=$(patsubst %.cpp,%.cpp.o,$(SRC_CXX))
OBJS:=$(OBJS_CXX)

ALL=$(GETSET)
all:$(ALL)
	
$(ALL): $(OBJS)
	$(CXX) -o $@ $< $(LIBDIR) $(LIB)

$(OBJS): $(SRC_CXX)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

clean:
	rm $(OBJS) $(ADD)
