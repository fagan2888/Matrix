include ../make.inc

.SUFFIXES: .c .cu .cpp .cpp.u .c.o .cu.o

TARGET:=../lib/libMatrix.so
SRC_CXX:=Matrix.cpp
INCLUDE+=-I../include
OBJS_CXX:=$(patsubst %.cpp,%.cpp.o,$(SRC_CXX))
OBJS:=$(OBJS_CXX)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OPTS) -shared -o $@ $<

$(OBJS_CXX): $(SRC_CXX)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(OPTS) $(INCLUDE) -o $@ -c $<

cleanall: 
	$(RM) $(OBJS) $(TARGET)

clean:
	$(RM) $(OBJS)

distclean:
	$(RM) $(TARGET)
