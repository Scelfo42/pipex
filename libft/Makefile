# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:09:22 by cscelfo           #+#    #+#              #
#    Updated: 2023/05/12 16:00:38 by cscelfo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LIB = $(NAME).a

ARCL = ar -crs

CC = clang

DEBUG_FLAG = -g

OPT_FLAG = -O1

CFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAG) $(OPT_FLAG)

SRCS_DIR = srcs

OBJ_DIR = obj

LIB_DIR = lib

RM = rm -f

RMDIR = rm -rf

INCLUDE = header

MEM_DIR = mem

IS_SMTH_DIR = is_smth

STR_DIR = str

TO_SMTH_DIR = to_smth

PUT_DIR = put

LST_DIR = list

GNL_DIR = gnl

MAT_DIR = mat

PRINT_DIR = print

ARR_DIR = arr

MEM_FILES =	ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_malloc.c \
			ft_calloc.c ft_memcmp.c ft_free.c \

IS_SMTH_FILES = ft_isalpha.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_isdigit.c \

STR_FILES =	ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strlen.c ft_strdup.c \
			ft_strnstr.c ft_strncmp.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_strmapi.c \
			ft_striteri.c \

TO_SMTH_FILES = ft_tolower.c ft_toupper.c ft_atoi.c ft_itoa.c ft_atof.c ft_atol.c ft_stack_to_arr.c \

PUT_FILES =	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \

LST_FILES =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_init_node.c \
			ft_last_node.c ft_add_node_before.c ft_add_node_after.c ft_smallest_node.c \
			ft_biggest_node.c \

GNL_FILES = ft_get_next_line.c ft_get_next_line_utils.c \

MAT_FILES =	ft_split.c ft_matlen.c \

PRINT_FILES =	ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_u_nbr.c ft_print_hex.c \
				ft_print_ptr.c ft_printf.c \

ARR_FILES =	ft_arrcpy.c \

MEM_SRCS = $(addprefix $(MEM_DIR)/, $(MEM_FILES))

IS_SMTH_SRCS = $(addprefix $(IS_SMTH_DIR)/, $(IS_SMTH_FILES))

STR_SRCS = $(addprefix $(STR_DIR)/, $(STR_FILES))

TO_SMTH_SRCS = $(addprefix $(TO_SMTH_DIR)/, $(TO_SMTH_FILES))

PUT_SRCS = $(addprefix $(PUT_DIR)/, $(PUT_FILES))

LST_SRCS = $(addprefix $(LST_DIR)/, $(LST_FILES))

GNL_SRCS = $(addprefix $(GNL_DIR)/, $(GNL_FILES))

MAT_SRCS = $(addprefix $(MAT_DIR)/, $(MAT_FILES))

PRINT_SRCS = $(addprefix $(PRINT_DIR)/, $(PRINT_FILES))

ARR_SRCS = $(addprefix $(ARR_DIR)/, $(ARR_FILES))

SRCS_FILES =	$(MEM_SRCS) $(IS_SMTH_SRCS) $(STR_SRCS) $(TO_SMTH_SRCS) $(PUT_SRCS) \
				$(LST_SRCS) $(GNL_SRCS) $(MAT_SRCS) $(PRINT_SRCS) $(ARR_SRCS) \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))
 
GREY            = \033[0;30m
RED             = \033[0;31m
GREEN           = \033[0;32m
BOLD_GREEN	= \033[1;32m
BOLD_YELLOW	= \033[1;33m
BOLD_BLUE	= \033[1;34m
FUCHSIA         = \033[0;35m
CYAN            = \033[0;36m
NC              = \033[0m

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(INCLUDE)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME) dir check_library

$(NAME): $(SRCS) $(O_SRCS)
	$(ARCL) $(LIB) $(O_SRCS)
	mkdir -p $(LIB_DIR)
	mv -u $(LIB) $(LIB_DIR)

dir:
	if [ -d "$(SRCS_DIR)" ]; then \
		echo "$(GREEN)PERFECT! All files are compiled correctly!$(NC)"; \
	else \
		echo "$(RED)ERROR! Something went wrong in the compilation, please check if everything is corrected in $(BOLD_BLUE)$(SRCS_DIR)$(NC)"; \
	fi
	@sleep 0.6

check_library:
	if [ -f "$(LIB_DIR)/$(LIB)" ]; then \
		echo "$(BOLD_GREEN)$(LIB) $(GREEN)was created correctly!$(NC)"; \
	else \
		echo "$(RED)Something went wrong in the creation of $(BOLD_YELLOW)$(LIB)!$(NC)"; \
	fi
	@sleep 0.6 
	@clear

clean: check_obj_existence
	$(RMDIR) $(OBJ_DIR)
	if [ -d "$(OBJ_DIR)" ]; then \
		echo "$(RED)Something went wrong while cleaning!$(NC)"; \
	else \
		echo "$(GREEN)My man I fucking destroyed $(BOLD_BLUE)$(OBJ_DIR)$(GREEN), she deserved it.$(NC)"; \
	fi
	@sleep 0.5
	clear

check_obj_existence:
	if [ ! -d "$(OBJ_DIR)" ]; then \
		echo "Bro... I got nothing to clean. My job here is done.$(NC)"; \
		sleep 2; \
		clear; \
		exit 69; \
	fi

fclean: check_lib_existence
	$(RMDIR) $(LIB_DIR)
	if [ -d "$(LIB_DIR)" ]; then \
		echo "$(RED)Something went wrong while fcleaning!$(NC)"; \
	else \
		echo "$(GREEN)That $(BOLD_YELLOW)$(LIB)$(GREEN) was shit$(NC)"; \
	fi
	@sleep 1.5 
	clear

check_lib_existence:
	if [ ! -d "$(LIB_DIR)" ]; then \
		echo "Before destroy something, you have to create it. Idiot."; \
		sleep 2; \
		clear; \
		exit 69; \
	fi

re: fclean all
	clear

push:
	git add .
	@echo "$(RED)Adding all changes..."
	sleep 1.5
	@clear
	@echo "$(GREEN)All changes added$(NC)"
	@read -p "Enter a custom commit message (leave blank to use the default message): " message; \
	if [ -n "$$message" ]; then \
		git commit -m "$$message"; \
	else \
		git commit -m "$(shell date +'%H:%M %d-%h') update"; \
	fi
	@echo "$(YELLOW)Committing...and..."
	git push
	@echo "$(GREEN)PUSHA KEKKO!$(NC)"uik5t6yt

norm:
	norminette *

.PHONY: all clean fclean re norm push wait
.SILENT:
