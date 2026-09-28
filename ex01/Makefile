CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD

OBJ_DIR = objs
NAME = Span

SRCS = main.cpp Span.cpp
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPENDS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPENDS)