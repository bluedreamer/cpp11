CXX=g++
CC=gcc
CC_SOURCE=${shell find . -name "*.cc"}
OBJS=${CC_SOURCE:.cc=.o}
TARGETS=${CC_SOURCE:.cc=}
CXXFLAGS=-std=c++0x -ggdb3 -Wall -Wextra -pedantic -Weffc++
LDFLAGS=
LIBPATH=
LIBRARIES=

.PHONY: all clean
.SUFFIXES:

all: bin ${TARGETS}

bin:
	mkdir bin

clean:
	rm -f ${OBJS} ${CC_SOURCE:.cc=.d} *.gcda *.gcno *.gcov bin/*

%: %.o
	${CXX} ${LIBPATH} ${LDFLAGS} ${LIBRARIES} $< -o bin/$@

%.o: %.cc
	$(CXX) -MD -c ${CXXFLAGS} $< ${INCLUDE} ${DEFINES} -o $@

-include ${CC_SOURCE:.cc=.d}
