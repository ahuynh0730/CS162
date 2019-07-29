
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o Sorting.o

SRCS = main.cpp inputValidation.cpp Sorting.cpp

HEADERS = inputValidation.hpp Sorting.hpp

VectorSearchSort: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o VectorSearchSort

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o VectorSearchSort