
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o Menu.o Recursion.o

SRCS = main.cpp inputValidation.cpp Menu.cpp Recursion.cpp

HEADERS =inputValidation.hpp Menu.hpp Recursion.hpp

recursion: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o recursion

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o recursion