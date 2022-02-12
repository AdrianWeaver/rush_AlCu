# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aweaver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 10:58:46 by aweaver           #+#    #+#              #
#    Updated: 2022/02/12 11:38:52 by aweaver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=			./a.out

CC				=			gcc

CFLAGS			=			-MMD -Wall -Wextra -Werror

LIBFT_PATH		=			./libft/
SRCS_PATH		=			./sources/
OBJS_PATH		=			./objs/

INC				=			-I $(addprefix $(LIBFT_PATH),includes/)

SRCS			=			ft_display_board.c

OBJS			=			$($(addprefix $(OBJS_PATH),SRCS:.c=.o))

DEPS			=			$(OBJS:.o=.d)

LIBFT			=			$(addprefix $(LIBFT_PATH),libft.a)

all:						$(NAME)

$(NAME):					$(OBJS) $(LIBFT)
							$(CC) $(CFLAGS) $^ -o $@ $(INC)

$(LIBFT):
							$(MAKE) -C $(LIBFT_PATH)

$(OBJS_PATH)%.o:			$(SRCS_PATH)%.c
							@mkdir -p $(OBJS_PATH)
							$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:			
							rm -rf $(OBJS_PATH)
							$(MAKE) -C $(LIBFT_PATH) clean

fclean:						clean
							rm -f $(NAME)
							$(MAKE) -C $(LIBFT_PATH) fclean

re:							
							fclean all
							$(MAKE) -C $(LIBFT_PATH) re

-include $(DEP)

.PHONY:						re all clean fclean
