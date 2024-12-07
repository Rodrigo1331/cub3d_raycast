# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 20:32:02 by joaosilva         #+#    #+#              #
#    Updated: 2024/12/03 16:28:43 by rcruz-an         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################  Variables ######################
NAME = cub3d
# NAME_BONUS = so_long_bonus
# Other Variables
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g #-O3 #-g #-fsanitize=address #-pthread ead #-fsanitize=add
INCLUDE = -I include

############  Source files - Sources to objects ###########
SRC_FILES = main.c parser/tokenizer.c parser/lexer.c parser/check_map.c \
movement/handle_keys.c movement/linear_moves.c movement/rotation.c \
rendering/raycasting.c rendering/dda.c rendering/draw.c \
exit_error/exit_free_game.c \
 
SRC_DIR = src/
SRC = ${addprefix ${SRC_DIR}, ${SRC_FILES}}
# SRC = $(addsuffix .c, $(SRC_FILES))

########### Object files ###########
OBJS = ${addprefix obj/, ${SRC_FILES:.c=.o}}
#OBJ_DIR = objects/
#OBJS = ${addprefix ${OBJ_DIR}, ${SRC_FILES:.c=.o}}

############ Header files same folder ###########
HEADER_FILES = cub3d.h
#HEADER_BONUS_FILES = so_long_bonus.h
HEADER_DIR = include
HEADER = ${addprefix ${HEADER_DIR}/, ${HEADER_FILES}}
#HEADER_BONUS = ${addprefix ${HEADER_DIR}/, ${HEADER_BONUS_FILES}}

###Libft
LIBFT = -L Libft_obj -lft -lm

###GNL
#GET_NEXT_LINE = -L get_next_line_obj -lgnl

# Variáveis/Caminho para MiniLibX no Linux
#MINILIBX_LINUX = -L minilibx-linux -lmlx -lXext -lX11

# Variáveis/CAminho para MiniLibX no macOS
#MINILIBX_MACOS = -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

# Verifica o sistema operacional
UNAME_S := $(shell uname -s)

# este dá erro:  Escolhe as variáveis apropriadas com base no sistema operacional
#ifeq ($(UNAME_S),Linux)
#    MINILIBX = $(MINILIBX_LINUX)
#else ifeq ($(UNAME_S),Darwin)
#    MINILIBX = $(MINILIBX_MACOS)
#else
#    $(error Sistema operacional não suportado: $(UNAME_S))
#endif

# Escolhe as variáveis apropriadas com base no sistema operacional
ifeq ($(UNAME_S),Linux)
    MINILIBX = -L minilibx-linux -lmlx -lXext -lX11
else ifeq ($(UNAME_S),Darwin)
    MINILIBX = -L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit
else
    $(error Sistema operacional não suportado: $(UNAME_S))
endif

#######################   Rules ######################
### cria o so_long. congrega todos os ficheiros objetos, o header, o libft e a minilibx.
all: ${NAME}
${NAME}: ${OBJS} ${HEADER}
	@make -s -C Libft
#@make -s -C get_next_line
ifeq ($(UNAME_S),Linux)
	@make -s -C minilibx-linux
else 
#	@make -s -C minilibx_opengl_20191021
#minilibx_macos:
	@make -C minilibx_opengl_20191021
	@echo "$(GREEN)\nCompilando MiniLibX para macOS...$(DEF_COLOR)"
endif
	@${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${OBJS} ${LIBFT} ${MINILIBX}
	@echo "$(GREEN)\n${NAME} created$(DEF_COLOR)"

###criar a diretoria obj e cria os objetos a partir dos ficheiros .c
obj/%.o: ${SRC_DIR}/%.c ${HEADER}
	@mkdir -p $(dir $@)
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@
	@echo "$(GRAY) Object $(basename $(notdir $@)) files created with success$(DEF_COLOR)"

clean:
	@make fclean -s -C Libft
#@make fclean -s -C get_next_line
ifeq ($(UNAME_S),Linux)
#	@make clean -s -C minilibx-linux
#	@${RM} -r minilibx-linux     #commented, otherwise 'make re' wouldn't work
#	@${RM} -r minilibx-linux.tgz #commented, otherwise 'make re' wouldn't work
else ifeq ($(UNAME_S),Darwin)
#	@${RM} -r minilibx_opengl_20191021
#	@${RM} -r minilibx_opengl.tgz
# @make clean -C minilibx_opengl_20191021
# @make clean -s -C minilibx_opengl_20191021
endif
	@${RM} ${OBJS}
	@${RM} -r obj
	@echo "$(RED)\nObject files removed$(DEF_COLOR)"


###remove o cub3d e o cub3d_bonus
fclean: clean
	@${RM} ${NAME}
#removed ${NAME_BONUS} at the above rm
	@echo "$(RED)\n${NAME} removed$(DEF_COLOR)"

###shell script for one map
run:
	@MAP_COUNT=$$(find maps -maxdepth 1 -type f -name "*.cub" | wc -l); \
	read -p "Escolha um mapa (0 a $$((MAP_COUNT-1))): " MAP_INDEX; \
	MAP_FILE=$$(find maps -maxdepth 1 -type f -name "*.cub" | sed -n "$$(($$MAP_INDEX + 1))p"); \
	if [ -z "$$MAP_FILE" ]; then \
		echo "$(YELLOW)Mapa inválido. Certifique-se de que o índice está correto.$(DEF_COLOR)"; \
	elif [ -x "cub3d" ]; then \
		./cub3d "$$MAP_FILE"; \
	else \
		echo "$(RED)O executável 'cub3d' não foi encontrado. Compile o projeto e tente novamente.$(DEF_COLOR)"; \
	fi

###shell script for all maps
runall:
	@MAP_COUNT=$$(find maps -maxdepth 1 -type f -name "*.cub" | wc -l); \
	if [ $$MAP_COUNT -eq 0 ]; then \
		echo "$(YELLOW)Nenhum mapa encontrado na pasta 'maps'.$(DEF_COLOR)"; \
		exit 1; \
	fi; \
	read -p "Selecione o mapa inicial (0 a $$((MAP_COUNT-1))): " START_INDEX; \
	for i in $$(seq $$START_INDEX $$((MAP_COUNT-1))); do \
		MAP_FILE=$$(find maps -maxdepth 1 -type f -name "*.cub" | sed -n "$$(($$i + 1))p"); \
		echo "$(CYAN)Iniciando o mapa $$i: $$MAP_FILE...$(DEF_COLOR)"; \
		if [ -x "cub3d" ]; then \
			OUTPUT=$$(./cub3d "$$MAP_FILE"); \
		else \
			echo "$(RED)O executável 'cub3d' não foi encontrado. Compile o projeto e tente novamente.$(DEF_COLOR)"; \
			exit 1; \
		fi; \
		echo "$$OUTPUT"; \
		echo "$$OUTPUT" | grep -q "Jogo concluído! Parabéns!"; \
		if [ $$? -eq 0 ]; then \
			echo "$(GREEN)Mapa $$i concluído com sucesso!$(DEF_COLOR)"; \
		else \
			echo "$(YELLOW)O mapa $$i não foi completado.$(DEF_COLOR)"; \
			read -p "Deseja tentar novamente? (y/n): " CHOICE; \
			if [ "$$CHOICE" != "y" ]; then \
				break; \
			fi; \
		fi; \
	done; \
	echo "$(CYAN)Todos os mapas foram executados!$(DEF_COLOR)"

###o fcleansoft existe para uma versão soft da compilação, sem incluir a biblioteca, senão além de demorar muito, gastamos recursos desnecessariamente.
fcleansoft:
	@${RM} ${OBJS}
#removed ${OBJS_BONUS} at the above rm
	@${RM} -r obj
#removed obj_bonus at the above rm
	@echo "$(RED)\nObject files removed$(DEF_COLOR)"
	@${RM} ${NAME}
#removed ${NAME_BONUS} at the above rm
	@echo "$(RED)\n${NAME} removed$(DEF_COLOR)"

###faz download automático da biblioteca, diretamente da página do intra.
#downloadminilibx:
#	@wget https://projects.intra.42.fr/so_long/jode-jes#:~:text=minilibx%2Dlinux.tgz-,minilibx_opengl.tgz,-minilibx_mms_20200219_beta.tgz
#	@tar -xzf minilibx-linux.tgz


# Verifica o sistema operacional
UNAME_S := $(shell uname -s)

# Define o comando de download e descompactação com base no sistema operacional
ifeq ($(UNAME_S),Linux)
    DOWNLOAD_CMD := wget
    TAR_CMD := tar -xzf
    MINILIBX_URL := https://cdn.intra.42.fr/document/document/25858/minilibx-linux.tgz 
else
    DOWNLOAD_CMD := curl -LO
    TAR_CMD := tar -xzf
    MINILIBX_URL := https://cdn.intra.42.fr/document/document/25859/minilibx_opengl.tgz

endif

downloadminilibx:
	@$(DOWNLOAD_CMD) $(MINILIBX_URL)
	@$(TAR_CMD) $(shell basename $(MINILIBX_URL))
#	@$(TAR_CMD) $(notdir $(MINILIBX_URL))
ifeq ($(UNAME_S),Linux)
	@echo "$(GREEN)\n MINILIBX LINUX downloaded and folder created$(DEF_COLOR)"
else
	@echo "$(GREEN)\n MINILIBX MacOS downloaded and folder created$(DEF_COLOR)"
endif

cleanlibrary:
ifeq ($(IS_LINUX),1)
	@${RM} -rf minilibx-linux
	@echo "$(RED)\n MINILIBX LINUX objects cleaned and folder deleted$(DEF_COLOR)"
else
	@${RM} $(notdir $(MINILIBX_URL))
	@${RM} -rf minilibx_opengl_20191021
	@echo "$(RED)\n MINILIBX MacOS objects cleaned and folder deleted$(DEF_COLOR)"
endif



### primeiro faz o fclean (ou seja, o clean, eliminando os objetos, e dps elimina o libft.a), e a seguir torna a compilar tudo com o all (os objetos e o libft.a)
re: fclean all



### o rebsoft existe para uma versão soft da compilação, sem incluir a biblioteca
rebsoft: fcleansoft bonus


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


git :
	@ clear && sleep 1 && echo "$(RED)\n\n\n\nStart cleanning...\n\n" && sleep 1
	@ make fclean
	@ echo "$(CYAN)\n\n\n\nEverything clean\n\n\n$(GREEN)Git status:\n\n$(DEF_COLOR)"
	@ git status && sleep 1 && echo "$(RED)Press Enter to confirm" && read enter
	@ echo "$(DEF_COLOR)\nGit add everything\n\n"
	@ git add . && git status
	@ echo "$(YELLOW)" && read -p "Enter commit message: " message && read -p "Enter commit comment: " comment && git commit -m "$message" -m "$comment"
	@ echo "$(GRAY)" && git push
	@ echo "$(GREEN)\n\nGit push done with sucess\n\n$(DEF_COLOR)"



### phony faz com que o nome destes comandos não sejam confundidos com ficheiros. ou seja, se houver um ficheiro com esse nome para ser compilado ou atualizado, o compilador ignora.
.PHONY: all clean fclean re bonus



### o silent faz com que as ações ocorram, mas que não apareçam no terminal. Daí o nome silent, pq apesar de ocorreram as ações, elas são silenciosas...não aparecem no terminal.
#.SILENT:
