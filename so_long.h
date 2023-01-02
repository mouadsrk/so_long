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
# include<stdlib.h>

typedef struct t_h_v
{
    int ph;
    int pv; 
    int eh;
    int ev;
    int *h;
    int *v;
}t_h_v;

typedef struct Queue
{
 int front ;
 int rear  ;
 int *h;
 int *v;
 int size;
 char ** map_dimen;
}Queue;


int player_move(char **m);
int player_range(t_h_v el_po,size_t map_nodes,char **m);
void free_t_h_v(t_h_v *e);
void freeQueue(Queue **p);
void deQueue(Queue *p);
Queue* new_Queue(int SIZE);
void enQueue(int h,int v,Queue *p);
int number_of_element(t_h_v *s ,char ** map);
int map_data(char ** m, int *i);
void	ft_free(char **arr, int r);
int     map_quality(char ** map);
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