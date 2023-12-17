CXX = g++
CXXFLAGS = -std=c++11 -Wall
LIBFLAGS = -L. -ldatabase -lposition

SRCS = Database.cpp Position.cpp Menu.cpp
HEADERS = Database.h Position.h
OBJS = $(SRCS:.cpp=.o)
EXEC = menu_program

all: libdatabase libposition $(EXEC)

libdatabase: Database.o
	ar rcs libdatabase.a Database.o

libposition: Position.o
	ar rcs libposition.a Position.o

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) $(LIBFLAGS)

$(OBJS): $(HEADERS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC) libdatabase.a libposition.a
