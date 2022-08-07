CC=g++
CFLAGS =-c -g
LDFLAGS=-g
SRC=${wildcard src/*.cpp}
HDR=${wildcard include/*.hpp}
OBJ=${SRC:.cpp=.o}
EXEC=rython

all: ${SRC} ${OBJ} ${EXEC}

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.o: %.c ${HDR}
	${CC} ${CFLAGS} $< -o $@

clean:
	rm *.o ${EXEC}