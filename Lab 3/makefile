
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o Dice.o Game.o LoadedDice.o inputValidation.o Menu.o Player.o

SRCS = main.cpp Dice.cpp Game.cpp LoadedDice.cpp inputValidation.cpp Menu.cpp Player.cpp

HEADERS = Dice.hpp Game.hpp LoadedDice.hpp inputValidation.hpp Menu.hpp Player.hpp

diceWar: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o diceWar

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o diceWar