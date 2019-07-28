CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o Animal.o inputValidation.o Menu.o Penguin.o Tiger.o Turtle.o Zoo.o

SRCS = main.cpp Animal.cpp inputValidation.cpp Menu.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp 

HEADERS = Animal.hpp inputValidation.hpp Menu.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp

zoo: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o zoo

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o zoo