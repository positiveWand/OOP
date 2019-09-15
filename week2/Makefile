.SUFFIXES:  .cpp .o

OBJECTS = print.o student_id.o main.o

CXX = g++
CPPFLAGS = -c

TARGET = test

$(TARGET) : $(OBJECTS)
		$(CXX) -o $(TARGET) $(OBJECTS)

print.o : print.cpp

student_id.o : student_id.cpp

main.o : main.cpp

clean :
		rm -rf $(OBJECTS) $(TARGET)
