
NAME = minishell

CFLAGS = -Wall -Wextra -Werror -lreadline

RM = rm -rf

SRCS = 	minishell.c\
		utils/ft_split.c\
		utils/ft_strjoin.c\
		utils/ft_strncmp.c\
		utils/ft_strchr.c\
		utils/ft_strlen.c\
		utils/ft_strdup.c\
		
$(NAME) :
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) $(NAME)

re : fclean all
