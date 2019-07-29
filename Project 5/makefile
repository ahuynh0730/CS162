
CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
LDFLAGS = -lboost_date_time

OBJS = main.o Board.o Bun.o Cheese.o DeliverOrder.o Ingredient.o Lettuce.o Meat.o Onion.o Pickle.o Space.o Tomato.o Trash.o Player.o

SRCS = main.cpp Board.cpp Bun.cpp Cheese.cpp DeliverOrder.cpp Ingredient.cpp Lettuce.cpp Meat.cpp Onion.cpp Pickle.cpp Space.cpp Tomato.cpp Trash.cpp Player.cpp

HEADERS = Board.hpp Bun.hpp Cheese.hpp DeliverOrder.hpp Ingredient.hpp Lettuce.hpp Meat.hpp Onion.hpp Pickle.hpp Space.hpp Tomato.hpp Trash.hpp Player.hpp

BurgerMania: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o BurgerMania

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o BurgerMania