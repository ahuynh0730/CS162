
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o Menu.o Node.o DoublyLinkedList.o

SRCS = main.cpp inputValidation.cpp Menu.cpp Node.cpp DoublyLinkedList.cpp

HEADERS =inputValidation.hpp Menu.hpp Node.hpp DoublyLinkedList.hpp

DoubleLinkedList: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o DoubleLinkedList

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o DoubleLinkedList