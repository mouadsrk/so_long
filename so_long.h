/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:47:37 by mserrouk          #+#    #+#             */
/*   Updated: 2023/01/11 23:25:39 by mserrouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	ph;
	int	pv;
	int	eh;
	int	ev;
	int	*h;
	int	*v;
}t_h_v;

typedef struct queue
{
	int	front;
	int	rear;
	int	*h;
	int	*v;
	int	size;
}t_queue;

typedef struct s_vars {
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
	void	*i_r;
	void	*i_rl;
	int		d;
	int		c;
	int		rd;
	int		number;
}t_vars;

int		display_enemie(t_vars *v);
char	*ft_itoa(int n);
void	display(t_vars *vars);
void	mlx_graphiqueb(t_vars *vars);
void	mlx_graphique(t_vars *vars);
char	**ft_read(char **av);
void	move_leftb(t_h_v *e_p, t_vars *vars);
void	move_rightb(t_h_v *e_p,	t_vars *vars);
void	move_downb(t_h_v *e_p, t_vars *vars);
void	move_upb(t_h_v *e_p, t_vars *vars);
void	player_moveb(t_vars *vars, int keycode);
void	move_left(t_h_v *e_p, t_vars *vars, int *number);
void	move_right(t_h_v *e_p,	t_vars *vars, int *number);
void	move_down(t_h_v *e_p, t_vars *vars, int *number);
void	move_up(t_h_v *e_p, t_vars *vars, int *number);
void	player_move(t_vars *vars, int keycode);
int		player_range(t_h_v el_po,	size_t map_nodes,	char **m);
void	free_t_h_v(t_h_v *e);
void	freequeue(t_queue **p);
void	dequeue(t_queue *p);
t_queue	*new_queue(int SIZE);
void	enqueue(int h,	int v, t_queue *p);
int		number_of_element(t_h_v *s, char **map);
int		map_data(char **m);
void	ft_free(char **arr, int r);
int		map_qualityb(char **map);
int		map_quality(char **map);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n, int len);
int		ft_putstr(char *s);
int		ft_unsignedputnbr(unsigned int nb, int len);
int		hexa(unsigned int i, int len);
int		hexaup(unsigned int i, int len);
int		hexap(unsigned long long n, int len);
int		ft_strchr(char *str, char c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *save, char *buffer);
char	*get_next_line(int fd);
char	*adjust_next_line(char *save);
char	*read_line(int fd, char *save);
char	*ft_strdup(char *s1);
char	**ft_split(char const *s, char c);
#endif