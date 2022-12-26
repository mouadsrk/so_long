#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<stdio.h>
# include <unistd.h>
# include <fcntl.h> 
# include<stdlib.h>
# include<stdarg.h>


int     map_quality();
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_printf(const char *s, ...);
int     ft_putchar(char c);
int     ft_putnbr(int n, int len);
int     ft_putstr(char *s);
int     ft_unsignedputnbr(unsigned int nb, int len);
int     hexa(unsigned int i, int len);
int     hexaup(unsigned int i, int len);
int     hexap(unsigned long long n, int len);
int		ft_strchr(char *str, char c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *save, char *buffer);
char	*get_next_line(int fd);
char	*adjust_next_line(char *save);
char	*read_line(int fd, char *save);
char	*ft_strdup(char *s1);
char	**ft_split(char const *s, char c);
#endif