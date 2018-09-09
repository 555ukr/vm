NAME = abstractVM

CC = g++ -std=c++11

SRC_PATH = ./src/
INC_PATH = ./inc/

INC =	eOperandType.hpp \
			Execute.hpp \
			IOperand.hpp \
			Lexser.hpp \
			My_Exception.hpp \
			Parser.hpp \
			Type.hpp

SRC =	Execute.cpp \
			Lexser.cpp \
			main.cpp \
			My_Exception.cpp \
			Parser.cpp

OBJ = $(SRC:.cpp=.o)
OBJ_DIR = obj
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ_SRC)
	$(CC) -g -Wall -Werror -Wextra $(OBJ_SRC) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_PATH)%.cpp
	@/bin/mkdir -p $(OBJ_DIR)
	@$(CC)  -g -Wall -Werror -Wextra -I$(INC_PATH) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
