
# Cody Barnson
# makefile for recursive tree animation and rain animation

CC = g++
CCFLAGS = -Wall -g -std=c++11 `pkg-config allegro-5 --cflags`

# file names
TREESOURCE = $(filter-out main-triangle.cc, $(wildcard *.cc))
TREEOBJECT = $(TREESOURCE:.cc=.o)
RAINSOURCE = $(filter-out main-line.cc, $(wildcard *.cc))
RAINOBJECT = $(RAINSOURCE:.cc=.o)


LNFLAGS = -lallegro -lallegro_primitives `pkg-config allegro-5 --libs`

# main target
all: rain tree

rain: $(RAINOBJECT)
	$(CC)  -o $@ $^ $(LNFLAGS)

tree: $(TREEOBJECT)
	$(CC)  -o $@ $^ $(LNFLAGS)

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



# LIBDIR = -L/home/lib2720/allegro/lib
# $(LIBDIR)
# $(LIBDIR)