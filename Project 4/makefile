
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o inputValidation.o Menu.o Barbarian.o BlueMen.o Character.o Dice.o HarryPotter.o Medusa.o Vampire.o Queue.o

SRCS = main.cpp inputValidation.cpp Menu.cpp Barbarian.cpp BlueMen.cpp Character.cpp Dice.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp Queue.cpp

HEADERS = inputValidation.hpp Menu.hpp Barbarian.hpp BlueMen.hpp Character.hpp Dice.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp Queue.hpp

FantasyCombatTournament: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o FantasyCombatTournament

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o FantasyCombatTournament