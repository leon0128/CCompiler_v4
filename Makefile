CXX      = g++-8
CXXFLAGS = -std=c++11 $(DEBFLAGS)
DEBFLAGS = -g3 -Wall
OBJS     = $(patsubst %.cpp, %.o, $(wildcard $(SRCDIR)*.cpp))
PROGRAM  = Compiler

SRCDIR = src/

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(PROGRAM)

clean:; rm -f *.o */*.o *~ $(PROGRAM)