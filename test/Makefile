include ../make.inc

ADD:=add
SUB:=sub
GETSET:=getset
TEST:=test
SRC_GETSET:=getsetelements.cpp
SRC_ADD=add.cpp
SRC_SUB=sub.cpp
SRC_TEST=testing.cpp
OBJS_GETSET:=$(patsubst %.cpp,%.cpp.o,$(SRC_GETSET))
OBJS_ADD:=$(patsubst %.cpp,%.cpp.o,$(SRC_ADD))
OBJS_SUB:=$(patsubst %.cpp,%.cpp.o,$(SRC_SUB))
OBJS_TEST:=$(patsubst %.cpp,%.cpp.o,$(SRC_TEST))
OBJS:=$(OBJS_GETSET) $(OBJS_ADD) $(OBJS_TEST) $(OBJS_SUB)

ALL=$(GETSET) $(ADD) $(SUB) $(TEST)

all:$(ALL)

$(ADD): $(OBJS_ADD)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(SUB): $(OBJS_SUB)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(GETSET): $(OBJS_GETSET)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(TEST): $(OBJS_TEST)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(OBJS_TEST): $(SRC_TEST)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_GETSET): $(SRC_GETSET)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_ADD): $(SRC_ADD)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_SUB): $(SRC_SUB)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

clean:
	rm $(OBJS)

cleanall:
	rm $(OBJS) $(ALL)
