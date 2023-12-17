CXX = gcc
CXXFLAGS = -std=c++11 -Wall

SRCS = Database.cpp Position.cpp Menu.cpp
HEADERS = Database.h Position.h

OBJS = $(SRCS:.cpp=.o)
EXEC = menu_app

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

$(OBJS): $(HEADERS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
