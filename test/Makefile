include ../make.inc

ADDSUB:=addsub
GETSET:=getset
TEST:=test
SRC_GETSET:=getsetelements.cpp
SRC_ADDSUB=addsub.cpp
SRC_TEST=testing.cpp
OBJS_GETSET:=$(patsubst %.cpp,%.cpp.o,$(SRC_GETSET))
OBJS_ADDSUB:=$(patsubst %.cpp,%.cpp.o,$(SRC_ADDSUB))
OBJS_TEST:=$(patsubst %.cpp,%.cpp.o,$(SRC_TEST))
OBJS:=$(OBJS_GETSET) $(OBJS_ADDSUB) $(OBJS_TEST)

ALL=$(GETSET) $(ADDSUB) $(TEST)
all:$(ALL)

$(ADDSUB): $(OBJS_ADDSUB)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(GETSET): $(OBJS_GETSET)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(TEST): $(OBJS_TEST)
	$(CXX) -o $@ $< $(LIBDIR) $(LDFLAGS)

$(OBJS_TEST): $(SRC_TEST)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_GETSET): $(SRC_GETSET)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

$(OBJS_ADDSUB): $(SRC_ADDSUB)
	$(CXX) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

clean:
	rm $(OBJS)
cleanall:
	rm $(OBJS) $(ALL)
