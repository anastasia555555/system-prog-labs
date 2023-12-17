CXX = g++
CXXFLAGS = -std=c++11 -Wall -fPIC
LIBFLAGS = -L. -ldatabase -lposition

SRCS = Database.cpp Position.cpp Menu.cpp
HEADERS = Database.h Position.h
OBJS = $(SRCS:.cpp=.o)
EXEC = menu_program

all: libdatabase libposition $(EXEC)

libdatabase: Database.o
	$(CXX) -shared -o libdatabase.so Database.o

libposition: Position.o
	$(CXX) -shared -o libposition.so Position.o

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) $(LIBFLAGS)

$(OBJS): $(HEADERS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC) libdatabase.so libposition.so
