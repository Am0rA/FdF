# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: itopchu <itopchu@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/22 15:13:30 by itopchu       #+#    #+#                  #
#    Updated: 2023/01/22 15:13:30 by itopchu       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line
HEADER	= ../header/
ARCHIVE_NAME = $(NAME).a
# **************************************************************************** #
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -I $(HEADER)
RM		= rm -rf
# **************************************************************************** #
AR		= ar
ARFLAGS	= -rcs
ARCHIVE	= $(AR) $(ARFLAGS)
# **************************************************************************** #
DIR_OBJ	= ../../obj/
# **************************************************************************** #
SRC		=	get_next_line_utils.c \
			get_next_line.c
# **************************************************************************** #
OBJ		= $(SRC:%.c=$(DIR_OBJ)%.o)
# **************************************************************************** #
$(DIR_OBJ)%.o: %.c $(HEADER)
	@$(COMPILE) -o $@ -c $<

$(ARCHIVE_NAME): $(OBJ)
	@$(ARCHIVE) $(ARCHIVE_NAME) $(OBJ)
	@echo "$(NAME) is compiled."
# **************************************************************************** #
all: $(ARCHIVE_NAME)

fclean:
	@$(RM) $(ARCHIVE_NAME)
	@echo "$(ARCHIVE_NAME) is removed"

re: fclean all

.PHONY: clean all fclean re