##############################################################
## ARGUMENTS
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -fPIC
AR					:= ar rcs
NAME				:= libftprintf.a

##############################################################
## SOURCES

SRC					:= ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_unsigned_nbr.c
OBJ					:= $(SRC:.c=.o)
LIBFT				:= Libft/libft.a

##############################################################
## RULES


all: check_libft
	$(MAKE) $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(AR) $@ $^ Libft/*.o

%.o:%.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re check_libft

clean:
	rm -f $(OBJ)
	make clean -C Libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean
	$(MAKE) all

check_libft: Libft/
	make -C Libft
