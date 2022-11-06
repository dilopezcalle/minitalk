# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 12:22:53 by dilopez-          #+#    #+#              #
#    Updated: 2022/08/11 07:41:25 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	libftprintf.a
DIR_OBJS 		=	objs/
DIR_INCLUDE		=	../../includes/
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

SRCS			=	ft_printf.c				\
					utils/ft_putchar.c		\
					utils/ft_putstr.c		\
					utils/ft_putnull.c		\
					utils/ft_putnbr.c		\
					utils/ft_putunsigned.c	\
					utils/ft_putptr.c		\

OBJS			=	$(SRCS:.c=.o)
OBJS_PREFIXED	=	$(addprefix $(DIR_OBJS), $(OBJS))

# ========== RULES ==========

$(DIR_OBJS)%.o : %.c
	@mkdir -p $(DIR_OBJS)/utils
	@echo "Compiling with $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -I $(DIR_INCLUDE) -c $< -o $@

$(NAME) : $(OBJS_PREFIXED)
	@ar csr $(NAME) $(OBJS_PREFIXED)

# ========== FUNCTIONS ==========

all: $(NAME)

clean:
	@rm -rf $(OBJS) $(DIR_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

#out: re
#	gcc $(CFLAGS) libftprintf.a -o a.out

.PHONY: all clean fclean re
