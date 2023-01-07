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
# include <mlx.h>

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
}Queue;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		mh;
	int		mv;
	int		p_im;
	void	*i_pl;
	void	*i_p;
	void	*i_e;
	void	*i_eo;
	void	*i_c;
	void	*i_w;
	void	*i_s;
	int		d;
	int		c;
}t_vars;


void display(t_vars *vars);
void    mlx_graphique(t_vars *vars);
char**	ft_read(char ** av);
void move_left(t_h_v *e_p,t_vars *vars  , int *number);
void move_right(t_h_v *e_p,t_vars *vars  , int *number);
void move_down(t_h_v *e_p,t_vars *vars  , int *number);
void move_up(t_h_v *e_p,t_vars *vars  , int *number);
void player_move(t_vars *vars, int keycode);
int player_range(t_h_v el_po,size_t map_nodes,char **m);
void free_t_h_v(t_h_v *e);
void freeQueue(Queue **p);
void deQueue(Queue *p);
Queue* new_Queue(int SIZE);
void enQueue(int h,int v,Queue *p);
int number_of_element(t_h_v *s ,char ** map);
int	map_data(char ** m);
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