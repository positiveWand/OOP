.SUFFIXES: .cpp .o

OBJECTS = vehicle.o car.o bike.o main.o

CXX = g++
CPPFLAGS = -c

TEST = test

$(TEST) : $(OBJECTS)
	$(CXX) -o $(TEST) $(OBJECTS)

clean:
	rm -rf $(TEST) $(OBJECTS)

vehicle.o : vehicle.cpp

car.o : car.cpp

bike.o : bike.cpp

main.o : main.cpp
