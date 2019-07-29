
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o Menu.o Lab9Functions.o

SRCS = main.cpp inputValidation.cpp Menu.cpp Lab9Functions.cpp

HEADERS = inputValidation.hpp Menu.hpp Lab9Functions.hpp

Lab9: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Lab9
${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o Lab9