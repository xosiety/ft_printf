# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:10:04 by afabbri           #+#    #+#              #
#    Updated: 2023/03/07 14:10:26 by afabbri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	printf.a

FLAGS		= -Wall -Werror -Wextra

SRCS		= ft_printf.c \
			  ft_printhex.c \
			  ft_printptr.c \
			  ft_unsignedprint.c\
			  ft_printf_utils.c \

OBJS		= $(SRCS:%.c=%.o)

LIBFTPATH	= ../libft

LIBFT		= libft.a

CC			= gcc $(FLAGS)

.o:.c
	$(CC) $(OBJS) $< $(LIBFTPATH)/$(LIBFT) -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFTPATH)/$(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "ft_printf created"

$(LIBFT):
	@make -C $(LIBFTPATH) all
	@echo "libft created"

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTPATH) clean
	@echo "objects deleted"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTPATH) fclean
	@echo "ft_printf deleted"

re: fclean all