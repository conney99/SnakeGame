CC =g++
OBJS = Charposition.o Display.o Gameplay.o Initialization.o Items.o main.o
CXXFLAGS = -W -Wall -O2
SRCS = Charposition.cpp Display.cpp Gameplay.cpp Initialization.cpp Items.cpp main.cpp
RUN = executiveFile

run : ${RUN}
${RUN} : ${OBJS}	
	@${CC} -o ${RUN} ${OBJS} -lncurses
	@rm *.o
	@./${RUN}
${OBJS} : ${SRCS}
	@${CC} ${CXXFLAGS} -c -o Charposition.o Charposition.cpp
	@${CC} ${CXXFLAGS} -c -o Display.o Display.cpp
	@${CC} ${CXXFLAGS} -c -o Gameplay.o Gameplay.cpp
	@${CC} ${CXXFLAGS} -c -o Initialization.o Initialization.cpp
	@${CC} ${CXXFLAGS} -c -o Items.o Items.cpp
	@${CC} ${CXXFLAGS} -c -o main.o main.cpp

clean :
	@rm *.o $(RUN)
