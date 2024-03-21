##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = nanotekspice

SRC = ./main.cpp \
	  ./src/Parsing.cpp \
	  ./src/Circuit.cpp \
	  ./src/Components/AComponent.cpp \
	  ./src/Components/GatesComponents/GatesComponents.cpp \
	  ./src/Components/SpecialComponents/False.cpp \
	  ./src/Components/SpecialComponents/True.cpp \
	  ./src/Components/SpecialComponents/Input.cpp \
	  ./src/Components/SpecialComponents/Clock.cpp \
	  ./src/Components/SpecialComponents/Output.cpp \
	  ./src/Components/ElementaryComponents/AND.cpp \
	  ./src/Pins/Pin.cpp \
      ./src/Components/ElementaryComponents/OR.cpp \
      ./src/Components/ElementaryComponents/XOR.cpp \
      ./src/Components/ElementaryComponents/NOT.cpp \
      ./src/Components/GatesComponents/Components4001.cpp \
      ./src/Components/GatesComponents/Components4011.cpp \
      ./src/Components/GatesComponents/Components4030.cpp \
      ./src/Components/GatesComponents/Components4069.cpp \
      ./src/Components/GatesComponents/Components4071.cpp \
      ./src/Components/GatesComponents/Components4081.cpp \

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -std=c++20

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME) -g3

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: $(OBJ)
	@g++ -o $(NAME) $(OBJ) -g3

.PHONY : all clean debug fclean re
