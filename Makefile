# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/12 19:19:51 by itopchu       #+#    #+#                  #
#    Updated: 2023/03/18 13:37:04 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m
# **************************************************************************** #
NAME	= fdf
# **************************************************************************** #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE	= $(CC) $(CFLAGS)
# **************************************************************************** #
RM		= rm -rf
# **************************************************************************** #
MLX_LIB	= ./inc/MLX42
MY_LIB	= ./inc/mylib
# **************************************************************************** #
HEADERS	= -I ./inc -I $(H_MY_LIB) -I $(H_MLX_LB)
H_MY_LIB= $(MY_LIB)/src/header
H_MLX_LB= $(MLX42)/include
# **************************************************************************** #
LIBS	= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(L_MLX_LB) $(L_MY_LIB)
L_MY_LIB= $(MY_LIB)/my_lib.a
L_MLX_LB= $(MLX_LIB)/build/libmlx42.a
# **************************************************************************** #
DIR_SRC	= src/
DIR_OBJ	= obj/
# **************************************************************************** #
SRCS	= $(addprefix $(DIR_SRC), $(SRCF))
SRCF	=	check_input.c \
			draw.c \
			init.c \
			utils.c \
			utils2.c \
			main.c
OBJS	= $(patsubst src/%.c,obj/%.o,$(SRCS))
# **************************************************************************** #

all		: dirs my_lib mlx_lib $(NAME)

dirs	:
	@mkdir -p $(DIR_OBJ)

my_lib	:
	@$(MAKE) -s -C $(MY_LIB)

mlx_lib	:
	@echo "$(YELLOW)MLX42 Compiling$(RESET)"
	@cmake $(MLX_LIB) -B $(MLX_LIB)/build && make -C $(MLX_LIB)/build -j4

obj/%.o: src/%.c
	@mkdir -p $(DIR_OBJ)
	@$(COMPILE) -c $< -o $@ $(HEADERS)

$(NAME)	: $(OBJS)
	@$(COMPILE) $(OBJS) -o $(NAME) $(LIBS) $(HEADERS)
	@echo "$(BLUE)$(BOLD)fdf: $(NAME) Compiled $(RESET)"

clean	:
	@$(RM) $(DIR_OBJ)
	@$(MAKE) -C $(MY_LIB) clean
	@rm -rf $(MLX_LIB)/build

fclean	: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(MY_LIB) fclean

re		: clean all

.PHONY	: all, clean, fclean, re, my_lib, mlx_lib