include ../make.inc

ADDSUB:=addsub
GETSET:=getset
LIB:=-lMatrix
LIBDIR:=-L../lib
INCLUDE:=-I../include
LDFLAGS:=
SRC_GETSET:=getsetelements.cpp
SRC_ADDSUB=addsub.cpp
OBJS_GETSET:=$(patsubst %.cpp,%.cpp.o,$(SRC_GETSET))
OBJS_ADDSUB:=$(patsubst %.cpp,%.cpp.o,$(SRC_ADDSUB))
OBJS:=$(OBJS_GETSET) $(OBJS_ADDSUB)

ALL=$(GETSET) $(ADDSUB)
all:$(ALL)

$(ADDSUB): $(OBJS_ADDSUB)
	$(CXX) -o $@ $< $(LIBDIR) $(LIB)

$(GETSET): $(OBJS_GETSET)
	$(CXX) -o $@ $< $(LIBDIR) $(LIB)

$(OBJS_GETSET): $(SRC_GETSET)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_ADDSUB): $(SRC_ADDSUB)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

clean:
	rm $(OBJS)
cleanall:
	rm $(OBJS) $(ALL)
