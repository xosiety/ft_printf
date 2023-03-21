# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afabbri <afabbri@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 14:10:04 by afabbri           #+#    #+#              #
#    Updated: 2023/03/15 13:12:58 by afabbri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FLAGS		= -Wall -Werror -Wextra

SRCS		= ft_printf.c \
			  ft_printhex.c \
			  ft_printptr.c \
			  ft_unsignedprint.c \
			  ft_printf_utilis.c \

OBJS		= $(SRCS:%.c=%.o)

LIBFTPATH	= ./libft

LIBFT		= libft.a

CC			= gcc $(FLAGS)

%.o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFTPATH)/$(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(LIBFT):
	@make -C $(LIBFTPATH) all

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFTPATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTPATH) fclean

re: fclean all
