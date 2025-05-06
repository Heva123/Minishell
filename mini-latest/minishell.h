

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int	    ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
int	    ft_strlen(const char *s);
char    *ft_strdup(const char *s1);


#endif