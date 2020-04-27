#
#
#

GCC = g++
GCC_OPTS = -std=c++11 -Wall -Wextra
PROGRAMS = find_roots

all: $(PROGRAMS)

find_roots: find_roots.o
	$(GCC) -o find_roots find_roots.o 

find_roots.o: find_roots.cpp
	$(GCC) -c find_roots.cpp $(GCC_OPTS)

check:
	echo "running make target 'check' ..."

distcheck:
	echo "running make target 'distcheck' ..."

clean:
	rm $(PROGRAMS) *.o

