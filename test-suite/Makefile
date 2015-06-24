include ../make.inc

LIBDIR:=$(LIBDIR) -L$(BOOSTLIB)/lib
LDFLAGS:=$(LDFLAGS) -lboost_unit_test_framework -lboost_system -lboost_timer
ADD:=add
GETSET:=getset
MULT:=multiply
SUB:=subtract
TEST:=test
SRC_ADD=add.cpp
SRC_GETSET:=getsetelements.cpp
SRC_MULT:=multiply.cpp
SRC_SUB=subtract.cpp
SRC_TEST=testing.cpp
OBJS_ADD:=$(patsubst %.cpp,%.cpp.o,$(SRC_ADD))
OBJS_GETSET:=$(patsubst %.cpp,%.cpp.o,$(SRC_GETSET))
OBJS_MULT:=$(patsubst %.cpp,%.cpp.o,$(SRC_MULT))
OBJS_SUB:=$(patsubst %.cpp,%.cpp.o,$(SRC_SUB))
OBJS_TEST:=$(patsubst %.cpp,%.cpp.o,$(SRC_TEST))

OBJS:=$(OBJS_ADD) $(OBJS_GETSET) $(OBJS_MULT) $(OBJS_SUB) $(OBJS_TEST)

ALL=$(ADD) $(GETSET) $(MULT) $(SUB) $(TEST) 

all:$(ALL)

$(ADD): $(OBJS_ADD)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(GETSET): $(OBJS_GETSET)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(MULT): $(OBJS_MULT)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(SUB): $(OBJS_SUB)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(TEST): $(OBJS_TEST)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)




$(OBJS_ADD): $(SRC_ADD)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_GETSET): $(SRC_GETSET)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_MULT): $(SRC_MULT)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_SUB): $(SRC_SUB)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_TEST): $(SRC_TEST)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

clean:
	rm $(OBJS)

cleanall:
	rm $(OBJS) $(ALL)
