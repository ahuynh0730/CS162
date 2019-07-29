
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o Menu.o Barbarian.o BlueMen.o Character.o Dice.o HarryPotter.o Medusa.o Vampire.o

SRCS = main.cpp inputValidation.cpp Menu.cpp Barbarian.cpp BlueMen.cpp Character.cpp Dice.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp

HEADERS = inputValidation.hpp Menu.hpp Barbarian.hpp BlueMen.hpp Character.hpp Barbarian.hpp BlueMen.hpp Character.hpp

FantasyCombat: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o FantasyCombat

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o FantasyCombat