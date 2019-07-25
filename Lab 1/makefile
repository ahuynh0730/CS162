CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o readMatrix.o determinant.o

SRCS = main.cpp readMatrix.cpp  determinant.cpp 

HEADERS = determinant.hpp readMatrix.hpp

matrix: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o matrix

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o matrix