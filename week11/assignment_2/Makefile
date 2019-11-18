.SUFFIXES: .cpp .o


OBJECTS = Integer.o Float.o Complex.o test.o

CXX = g++
TEST = test

$(TEST) :$(OBJECTS)
	$(CXX) -o $(TEST) $(OBJECTS)


Integer.o : Integer.cpp
Float.o : Float.cpp
Complex.o : Complex.cpp
test.o : test.cpp

clean :
	rm -rf $(TEST) $(OBJECTS)
