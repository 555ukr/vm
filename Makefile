NAME = ft_retro

CC = clang++

SRC_PATH = ./src/
INC_PATH = ./inc/

INC =	Board.hpp \
		Player.hpp \
		Shoot.hpp \
		Enemy.hpp \
		EnemyHorde.hpp \

SRC =	main.cpp \
		Board.cpp \
		Player.cpp \
		Enemy.cpp \
		Shoot.cpp \
		EnemyHorde.cpp \

OBJ = $(SRC:.cpp=.o)
OBJ_DIR = obj
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) -Wall -Werror -Wextra -lncurses $(OBJ_SRC) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_PATH)%.cpp
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC) -Wall -Werror -Wextra -I$(INC_PATH) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all