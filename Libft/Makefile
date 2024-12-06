# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 19:46:19 by joaosilva         #+#    #+#              #
#    Updated: 2024/11/29 01:37:38 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PART1 = ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
		ft_isdigit.c ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c \
		ft_strncmp.c ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c \
		ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c \
		ft_memset.c ft_memmove.c ft_strlcpy.c
		
PART2 = ft_itoa.c ft_strjoin.c ft_split.c ft_striteri.c ft_strmapi.c \
		ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c

NEW_INTRODUCTIONS_INTO_LIBFT = ft_strclen.c ft_intlen.c ft_puthex_fd.c ft_itoapositive.c \
							   ft_free_array.c ft_free_array_size.c ft_isspace.c \
							   ft_strchr_any.c

FT_PRINTF = ft_intlen.c ft_itoapositive.c ft_printf.c ft_puthex_fd.c print_chr.c \
			print_hex.c print_nbr.c print_pointer.c print_str.c print_unsigned.c

GNL = get_next_line_bonus.c ft_gnl_strchr.c ft_gnl_strjoin.c ft_gnl_strlen.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRC = ${PART1} ${PART2} ${NEW_INTRODUCTIONS_INTO_LIBFT} ${FT_PRINTF} ${GNL}
SRC_BONUS = ${BONUS}

OBJS = ${addprefix ../Libft_obj/, ${SRC:.c=.o}}
OBJS_BONUS = ${addprefix ../Libft_obj/, ${SRC_BONUS:.c=.o}}
HEADER = libft.h
INCLUDE = -I .
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror



### cria o libft.a. cria os ficheiro objeto, assim como o header. O bibft.a congrega todos os ficheiros objetos.
all: ${NAME}
$(NAME): ${OBJS} ${HEADER}
	ar rcs ../Libft_obj/${NAME} ${OBJS} ${HEADER}
	@echo "$(GREEN)\n${NAME} created$(DEF_COLOR)" 



### cria os objetos do mandatório e do bonus, assim como o header.
bonus: ${OBJS} ${OBJS_BONUS} ${HEADER}
	@ar rcs ../Libft_obj/${NAME} ${OBJS} ${OBJS_BONUS} ${HEADER}
	@echo "$(GREEN)\n$@ created$(DEF_COLOR)"



#criar a diretoria libft_obj e cria os objetos a partir dos ficheiros .c
../Libft_obj/%.o:%.c
	@mkdir -p ../Libft_obj
	${CC} ${CFLAGS} ${INCLUDE} -c -o $@ $^
	@echo "$(GRAY)\n$@ created$(DEF_COLOR)"



# remove os objetos e os objetos do bonus, assim como a pasta que os recebeu.
clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@${RM} -r ../Libft_obj
	@echo "$(RED)\nObjects deleted - libft$(DEF_COLOR)"



#remove o libft.a
fclean: clean
	${RM} ${NAME} 
	@echo "$(RED)\n${NAME} deleted\n$(DEF_COLOR)"



# primeiro faz o fclean (ou seja, o clean, eliminando os objetos, e dps elimina o libft.a), e a seguir torna a compilar tudo com o all (os objetos e o libft.a)
re: fclean all



#phony faz com que o nome destes comandos não sejam confundidos com ficheiros. ou seja, se houver um ficheiro com esse nome para ser compilado ou atualizado, o compilador ignora.
.PHONY: all clean fclean bonus re



#o silent faz com que as ações ocorram, mas que não apareçam no terminal. Daí o nome silent, pq apesar de ocorreram as ações, elas são silenciosas...não aparecem no terminal.
#.SILENT:

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
