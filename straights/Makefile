CXX=g++
CXXFLAGS=-std=c++14 -Werror=vla -MMD
OBJECTS=card.o player.o board.o game.o main.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=straights
${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}

