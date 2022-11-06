# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilopez- <dilopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 12:54:12 by dilopez-          #+#    #+#              #
#    Updated: 2022/08/11 08:41:36 by dilopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========== VARIABLES ==========
NAME			=	minitalk
SERVER			=	server
CLIENT			=	client
DIR_OBJ 		=	obj/
FT_PRINTF		=	libftprintf.a
DIR_INCLUDES	=	./includes/
RM				=	rm -rf
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra

SRC_SERVER		=	src/server.c		\
					src/ft_utils.c			\

SRC_CLIENT		=	src/client.c		\
					src/ft_utils.c			\

OBJ_SERVER		=	$(SRC_SERVER:.c=.o)
OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)
PREFIXED_SERVER	=	$(addprefix $(DIR_OBJ), $(OBJ_SERVER))
PREFIXED_CLIENT	=	$(addprefix $(DIR_OBJ), $(OBJ_CLIENT))

GREEN			=	"\\x1b[32m"
RED				=	"\\x1b[31m"
YELLOW			=	"\\x1b[33m"
RESET			=	"\\x1b[37m"

# ========== RULES ==========

$(NAME) : print_init $(SERVER)

$(SERVER) : $(PREFIXED_SERVER) print_nl $(CLIENT) print_finish
	@$(CC) $(CFLAGS) $(PREFIXED_SERVER) $(FT_PRINTF) -I $(DIR_INCLUDES) -o $(SERVER)

$(CLIENT) : $(PREFIXED_CLIENT)
	@echo "\n$(YELLOW)------------- Compiling ft_printf ------------$(RESET)\n"
	@make -C ./src/ft_printf
	@cp ./src/ft_printf/libftprintf.a .
	@$(CC) $(CFLAGS) $(PREFIXED_CLIENT) $(FT_PRINTF) -o $(CLIENT) -I $(DIR_INCLUDES)

$(DIR_OBJ)%.o : %.c
	@mkdir -p $(DIR_OBJ)/src/ft_printf/utils
	@echo "Compiling with $(CC) $(CFLAGS):\t $<"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INCLUDES)

# ========== FUNCTIONS ==========

print_init:
	@echo "\n$(YELLOW)---------- Compiling project's files ---------$(RESET)\n"

print_finish:
	@echo "\n${GREEN}---------- Mandatory part compiled! ----------${RESET}\n"

print_nl:
	@echo ""

all: $(NAME)

clean:
	@make -C ./src/ft_printf clean
	@rm -rf $(OBJ) $(DIR_OBJ)
	@echo "\n${GREEN}------------------ Cleaned! ------------------${RESET}\n"

fclean: clean
	@make -C ./src/ft_printf fclean
	@$(RM) $(SERVER) $(CLIENT) libftprintf.a

re: fclean all

.PHONY: all clean fclean re print bonus