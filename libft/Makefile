# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cscelfo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 12:09:22 by cscelfo           #+#    #+#              #
#    Updated: 2023/05/10 12:46:06 by cscelfo          ###   ########.fr        #
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

SMTH_TO_SMTH_DIR = smth_to_smth

PUT_DIR = put

LST_DIR = list

GNL_DIR = gnl

MAT_DIR = mat

PRINT_DIR = print

MEM_FILES =	ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_malloc.c \
			ft_calloc.c ft_memcmp.c ft_free.c \

IS_SMTH_FILES = ft_isalpha.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_isdigit.c \

MEM_SRCS = $(addprefix $(MEM_DIR)/, $(MEM_FILES))

IS_SMTH_SRCS = $(addprefix $(IS_SMTH_DIR)/, $(IS_SMTH_FILES))

SRCS =	ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strlen.c \
		ft_strdup.c ft_strnstr.c ft_strncmp.c \
		ft_atoi.c ft_strjoin.c ft_itoa.c ft_substr.c ft_strtrim.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_strmapi.c ft_striteri.c ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
		ft_get_next_line.c ft_get_next_line_utils.c ft_get_next_line_bonus.c \
		ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_u_nbr.c ft_print_hex.c \
		ft_print_ptr.c ft_printf.c ft_atof.c ft_atol.c ft_matlen.c \
 
GREY            = \033[0;30m
RED             = \033[0;31m
GREEN           = \033[0;32m
BOLD_GREEN		= \033[1;32m
BOLD_YELLOW		= \033[1;33m
BOLD_BLUE		= \033[1;34m
FUCHSIA         = \033[0;35m
CYAN            = \033[0;36m
NC              = \033[0m

all: $(NAME)

$(NAME): dir
	$(MAKE) -C $(SRCS_DIR)
	mv -u $(DIR)/$(LIB) $(LIB_DIR)
	clear

dir:
	if [ -d "$(SRCS_DIR)" ]; then \
		echo "$(GREEN)PERFECT! All files are compiled correctly!$(NC)"; \
	else \
		echo "$(RED)ERROR! Something went wrong in the compilation, please check if everything is corrected in $(BOLD_BLUE)$(SRCS_DIR)$(NC)"; \
	fi
	mkdir -p $(LIB_DIR)

check_library:
	if [ "$(LIB_DIR)/$(LIB)" ]; then \
		echo "$(BOLD_GREEN)$(LIB) $(GREEN)was created correctly!$(NC)"; \
	else \
		echo "$(RED)Something went wrong in the creation of $(BOLD_YELLOW)$(LIB)!$(NC)"; \
	fi

clean: check_clean wait
	$(MAKE) -C $(DIR) clean
	clear

check_clean:
	if ls $(DIR)/*.o > /dev/null 2>&1;  then \
		echo "$(GREEN)Everything was cleaned correctly!$(NC)"; \
	else \
		echo "$(RED)Something went wrong in clean!$(NC)"; \
	fi

fclean: check_fclean wait
	$(MAKE) -C $(DIR) fclean
	$(RMDIR) $(LIB_DIR)
	#clear

check_fclean:
	if ls $(LIB_DIR)/$(LIB) > /dev/null 2>&1;  then \
		echo "$(YELLOW)$(LIB) $(GREEN)and $(BLUE)$(LIB_DIR) $(GREEN)were removed correctly!$(NC)"; \
	else \
		echo "$(RED)Something went wrong in fclean!$(NC)"; \
	fi

re: fclean all
	$(MAKE) -C $(DIR) re
	#clear

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

wait:
	sleep 1

.PHONY: all clean fclean re norm push wait
.SILENT:
