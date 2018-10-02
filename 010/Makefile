#####
# tdterm Makefile:
# 	'make depend'	uses makedepend to automatically generate dependencies
# 					(dependencies are added to end of Makefile)
#	'make'			build executable file 'tdterm'
#	'make clean'	remove all .o files, executable files, and temporary files

#####
# Makefile variable/macro definitions
# Add or delete definitions as necessary to build the target

# Compiler to use and compiler settings
CXX = g++
CXXSTD = -std=c++11
CXXFLAGS = -Wall -Wno-unused -Werror -g -O2

# Libraries and headers to include
INCLUDES =
LFLAGS =
LIBS =

# Source files and object files
SRCS = util.cc tdterm.cc
OBJS = $(SRCS:.c=.o)

# Define the executable file(s)
TARGET = tdterm

#####
# The following section of the Makefile is generic; it can be used to build
# any executable just by changing the definitions above and by deleting
# dependencies appended to the file from 'make depend'

.PHONY: depend clean

all: $(TARGET)
	@echo tdterm compiled.

$(TARGET): $(OBJS)
	$(CXX) $(CXXSTD) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LFLAGS) $(LIBS)

# This is a suffix replacement rule for building .o files from .c files.
# It uses automatic variables: 
# 	$< - the name of the prerequisite of the rules (a .c file)
# 	$@ - the name of the target of the rule (a .o file)
# See the GNU Make Manual section about automatic variables for more info:
# https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
.c.o:
	$(CXX) $(CXXSTD) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o *~ $(TARGET)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
