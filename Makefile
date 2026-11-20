##############################################################
## ARGUMENTS
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -fPIC
AR					:= ar rcs
NAME				:= libftprintf.a

##############################################################
## SOURCES

SRC					:= ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_unsigned_nbr.c ft_print_hexa.c
OBJ					:= $(SRC:.c=.o)
LIBFT				:= Libft/libft.a

##############################################################
## RULES


all: check_libft
	$(MAKE) $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(AR) $@ $(OBJ) Libft/*.o

%.o:%.c ft_printf.h Libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re check_libft

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C Libft

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean
	$(MAKE) all

check_libft: Libft/
	$(MAKE) -C Libft
