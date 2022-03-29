CC = gcc
RM = rm

SRC = hello.c

all: hello hello_debug

clean:
	$(RM) hello hello_debug

##############################
# run with following command #
# $ ./hello                  #
##############################
hello:
	$(CC) $(SRC) -o $@

##############################
# run with following command #
# $ debug50 hello_debug      #
##############################
hello_debug:
	$(CC) -ggdb3 $(SRC) -o $@

##############################
# check the coding style     #
# $ style50 hello.c	         #
##############################

.PHONY: hello hello_debug
