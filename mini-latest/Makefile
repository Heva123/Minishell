
# NAME = minishell

# CFLAGS = -Wall -Wextra -Werror 

# RM = rm -rf

# SRCS = 	minishell.c\
# 		utils/ft_split.c\
# 		utils/ft_strjoin.c\
# 		utils/ft_strncmp.c\
# 		utils/ft_strchr.c\
# 		utils/ft_strlen.c\
# 		utils/ft_strdup.c\
		
# $(NAME) :
# 	gcc $(CFLAGS) $(SRCS) -o $(NAME)

# all : $(NAME)

# fclean : clean
# 	$(RM) $(NAME)

# clean :
# 	$(RM) $(NAME)

# re : fclean all

NAME = minishell

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lreadline

RM = rm -rf

SRCS = 	minishell.c \
		utils/ft_split.c \
		utils/ft_strjoin.c \
		utils/ft_strncmp.c \
		utils/ft_strchr.c \
		utils/ft_strlen.c \
		utils/ft_strdup.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(SRCS)
	gcc $(CFLAGS) $(SRCS) $(LDFLAGS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(NAME)

re: fclean all
