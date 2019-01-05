
# Cody Barnson
# makefile for recursive tree animation and rain animation

CC = g++11
CCFLAGS = -Wall -g -std=c++11 -I/home/lib2720/allegro/include

# file names
TREESOURCE = $(filter-out main-triangle.cc, $(wildcard *.cc))
TREEOBJECT = $(TREESOURCE:.cc=.o)
RAINSOURCE = $(filter-out main-line.cc, $(wildcard *.cc))
RAINOBJECT = $(RAINSOURCE:.cc=.o)

LIBDIR = -L/home/lib2720/allegro/lib
LNFLAGS = -lallegro -lallegro_primitives

# main target
all: rain tree

rain: $(RAINOBJECT)
	$(CC) $(LIBDIR) -o $@ $^ $(LNFLAGS)

tree: $(TREEOBJECT)
	$(CC) $(LIBDIR) -o $@ $^ $(LNFLAGS)

# pull in dependency info for existing .o files
-include $(OBJECTS:.o=.d)

# compile and generate dependency info
%.o: %.cc
	$(CC) -c $(CCFLAGS) $< -o $@
	$(CC) -M $(CCFLAGS) $*.cc > $*.d

.PHONY: clean
# clean out the directory but keep executables with command "clean"
clean : 
	rm -f *~ *.o *.d rain tree




