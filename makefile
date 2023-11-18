#Here we specify compiler
CC = g++
#Here we define include dir
INCLUDE = ./include/
SRC= ./src/

# compiler flags:
#-g flag adds debugging information to the executable file
#-Wall flag is used to turn on most compiler warnings
#CFLAGS = -g -c -Wall -I$(INCLUDE)
#This is for release purposes
#CFLAGS = -O -c -Wall -I$(INCLUDE)

#Here we define compilation flags. 
#-c is to create the .o file(s)
#-I is to include the header directory 
CFLAGS = -c -I$(INCLUDE)


#$(patsubst pattern,replacement,text)
#Below we assume that the .cpp source files are under $(SRC) directory
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard $(SRC)*.cpp))

#Defining executables file name
EXECUTABLE = LAN

#Here we define all rule and its dependencies
all: $(OBJECTS) $(EXECUTABLE)

# The $@ refers to the left side of : 
$(EXECUTABLE) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $@  

#The $< refers to the first item in the dependency list
#The $@ refers the target file, file.o.
#This is a suffix rule telling how to turn .cpp into .o file
%.o: %.cpp %.h
	$(CC) $(CFLAGS) $< -o $@

clean :
#FOR LINUX
	-rm -rf $(OBJECTS) $(EXECUTABLE) 

#FOR WINDOWS
#	del $(subst /,\,$(OBJECTS)) $(EXECUTABLE)


#Here we define a new rule by combining two predefined rules
reset: all clean