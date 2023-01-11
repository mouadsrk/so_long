# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mserrouk <mserrouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 23:52:36 by mserrouk          #+#    #+#              #
#    Updated: 2023/01/11 23:52:37 by mserrouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a


src = ft_printf.c ft_write.c ft_write2.c   get_next_line_utils.c  \
	stplit.c mapdata3.c player_range4.c Queue_operation.c  map_quality2.c \
	player_move.c move_up.c move_down.c move_left.c move_right.c make_map.c mlx_graphique.c  

srcb = ft_printf.c ft_write.c ft_write2.c   get_next_line_utils.c  \
	stplit.c mapdata3.c player_range4.c Queue_operation.c  map_quality2b.c \
	player_moveb.c move_upb.c move_downb.c move_leftb.c move_rightb.c make_map.c mlx_graphiqueb.c itoa.c \
	display_enemie.c


FLAGS = -Wall -Wextra  -Werror

CC = gcc

AR = ar rc

RM = rm -f

OBJ = $(src:.c=.o)

OBJB = $(srcb:.c=.o)

all : $(NAME)
	gcc $(FLAGS) so_long1.c $(NAME) -lmlx -framework OpenGL -framework AppKit -o so_long

$(NAME) : $(OBJ) 
	$(AR)  $(NAME) $(OBJ) 
		
%.o :%.c so_long.h
	$(CC) $(FLGS)  -c $<

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

BONUS : fclean 
	gcc $(FLAGS) so_longb1.c $(srcb) -lmlx -framework OpenGL -framework AppKit -o so_long

	

re : clean all 

.PHONY: clean fclean 