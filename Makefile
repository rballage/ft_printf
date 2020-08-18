# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 16:39:25 by ydonse            #+#    #+#              #
#    Updated: 2020/08/15 09:32:39 by rballage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SRC_PATH = src

SRC_NAME =  main.c ft_printf.c list.c ft_ftoa.c convert.c \
			handle_l.c handle_ll.c handle_floats.c \
			attributes_calculs.c calcul_plus.c calcul_sharp.c \
			calcul_precision.c calcul_min_field.c handle_h.c handle_hh.c \
			attribute_check.c attribute_check_2.c calcul_neg_min_field.c \
			check_modifiers.c handle_du.c handle_bases.c handle_scp.c\
			check_other_modifiers.c

CPPFLAGS = -I libft/includes/ -MMD

LDFLAGS = -L libft/ -lft

CC = gcc

CFLAGS =  -Werror -Wall -Wextra

DFLAGS = -ggdb

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

HEADER_PATH = includes/

HEADER_NAME = ft_printf.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(CFLAGS) $(DFLAGS) $(LDFLAGS) $^ -o $@


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(DFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	make clean -C libft/
	rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)
