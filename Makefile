#
# File:   Makefile
# Author: Christopher Champagne
# Desc:   Makefile for CIS 190 HW 4a
#

#########################################
# rules for compiling and linking files #
#########################################

# the rule to create hw2 executable depends on trains.o and hw2.o existing
# so that they can be linked together; if they don't exist, it will run
# the appropriate rule(s) to create the needed file(s)
2048: BlockClass.o GridClass.o main.o
	g++ BlockClass.o GridClass.o main.o -o 2048

# rules to compile the individual .o files
BlockClass.o: BlockClass.cpp
	g++ -c -Wall BlockClass.cpp

GridClass.o: GridClass.cpp
	g++ -c -Wall GridClass.cpp

main.o: main.cpp
	g++ -c -Wall main.cpp

run:
	./2048


########################################
# rules for cleaning away excess files #
########################################

# removes .o and executable files
clean:
	rm  -f *o 2048

# removes any temporary (~) files
cleaner: 
	rm  -f *~

# runs both clean and cleaner
cleanest: clean cleaner

