.SUFFIXES: .cpp .o

OBJECTS = gameTable.o block.o colorGroup.o bigBlock.o foldBlock.o treeBlock.o crossBlock.o

GAME_FILE = puyopuyo.o $(OBJECTS)
CXX = g++
CPPFLAGS = -c

GAME = puyopuyo


$(GAME) : $(GAME_FILE)
	$(CXX) -o $(GAME) $(GAME_FILE)

clean:
	rm -rf $(GAME) $(GAME_FILE)


gameTable.o : gameTable.cpp

block.o : block.cpp

colorGroup.o : colorGroup.cpp

bigBlock.o : bigBlock.cpp

foldBlock.o : foldBlock.cpp

treeBlock.o : treeBlock.cpp

crossBlock.o : crossBlock.cpp

puyopuyo.o : puyopuyo.cpp

