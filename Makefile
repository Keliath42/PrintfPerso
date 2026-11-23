##############################################################
## ARGUMENTS
CC					:= cc
CFLAGS				:= -Wall -Wextra -Werror -fPIC
AR					:= ar rcs
NAME				:= libftprintf.a

##############################################################
## SOURCES

SRC						:= ft_printf.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_unsigned_nbr.c ft_print_hexa.c
OBJ						:= $(SRC:.c=.o)
LIBFT_SRC				:= Libft/ft_putchar_fd.c Libft/ft_putnbr_fd.c Libft/ft_strlen.c
LIBFT_OBJ				:=$(LIBFT_SRC:.c=.o)

##############################################################
## RULES


all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT_OBJ)
	$(AR) $@ $(OBJ) $(LIBFT_OBJ)

%.o:%.c ft_printf.h Libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all
