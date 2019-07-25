
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o Ant.o Board.o inputValidation.o Menu.o

SRCS = main.cpp Ant.cpp Board.cpp inputValidation.cpp Menu.cpp

HEADERS = Ant.hpp Board.hpp inputValidation.hpp Menu.hpp

grid: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o grid

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o matrix