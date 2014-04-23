
all: libMatrix test

lib: 

libMatrix: 
	cd src && $(MAKE)
	cd test && $(MAKE)

lib:
	cd src && $(MAKE)

clean: 
	cd src && $(MAKE) cleanall
	cd test && $(MAKE) cleanall

cleanlib:
	cd src && $(MAKE) cleanall
