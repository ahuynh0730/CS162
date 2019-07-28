CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o count_letters.o output_letters.o

SRCS = main.cpp count_letters.cpp  output_letters.cpp 

HEADERS = count_letters.hpp output_letters.hpp

readFile: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o readFile

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o readFile