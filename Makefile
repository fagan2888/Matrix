
all: test

test:
	cd src && $(MAKE)
	cd test-suite && $(MAKE)

libMatrix: 
	cd src && $(MAKE)
	cd test-suite && $(MAKE)

lib:
	cd src && $(MAKE)

clean: 
	cd src && $(MAKE) cleanall
	cd test-suite && $(MAKE) cleanall

cleanall:
	cd src && $(MAKE) cleanall
	cd test-suite && $(MAKE) cleanall
