NAME = libftsolong.a

src = ft_printf.c ft_write.c ft_write2.c get_next_line.c  get_next_line_utils.c mapcheck.c \
	stplit.c

FLGS =  -Wall -Wextra  -Werror

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

.PHONY: clean fclean 