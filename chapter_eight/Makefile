NAME = state

SOURCE = src
INCLUDE = -I ./include

SRC =   $(SOURCE)/state.cpp \

OBJ = $(SRC:%.cpp=%.o)


CFLAGS = -Wall -Werror -Wextra -std=c++11

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(OBJ) -o $(NAME)

%.o: %.cpp
	c++ -c  $(INCLUDE) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: clean fclean all re
re:     fclean all