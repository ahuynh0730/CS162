
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o

SRCS = main.cpp inputValidation.cpp

HEADERS = inputValidation.hpp

FibonacciAnalysis: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o FibonacciAnalysis
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o FibonacciAnalysis