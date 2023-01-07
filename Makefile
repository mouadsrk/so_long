NAME = libftsolong.a

src = ft_printf.c ft_write.c ft_write2.c   get_next_line_utils.c  \
	stplit.c mapdata3.c player_range4.c Queue_operation.c  map_quality2.c \
	player_move.c move_up.c move_down.c move_left.c move_right.c make_map.c mlx_graphique.c

FLG =  -Wall -Wextra  -Werror

CC = cc

AR = ar rcs

RM = rm -f

OBJ = $(src:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	$(AR)  $(NAME) $(OBJ) 
		
%.o :%.c libftsolong.h
	$(CC) $(FLG)  -c $<

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all 


run: re
	gcc so_long1.c libftsolong.a  -lmlx -framework OpenGL -framework AppKit
	./a.out map.ber


.PHONY: clean fclean 