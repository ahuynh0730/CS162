
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o Menu.o Queue.o

SRCS = main.cpp inputValidation.cpp Menu.cpp Queue.cpp

HEADERS = inputValidation.hpp Menu.hpp Queue.hpp

CircularQueue: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o CircularQueue
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o CircularQueue