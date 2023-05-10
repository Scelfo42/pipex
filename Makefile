NAME = pipex

RM_DIR = rm -rf

CC = clang

DEBUG_FLAG = -g

CFLAGS = -Wall -Wextra -Werror $(DEBUG_FLAG)

OLD_PROJ = libft

INCLUDE = header

HEADER_1 = $(INCLUDE)/ft_$(NAME).h

HEADER_2 = $(OLD_PROJ)/$(INCLUDE)/$(OLD_PROJ).h

DEPS = $(INCLUDE)/ $(OLD_PROJ)/$(INCLUDE)

SRCS_DIR = srcs

OLD_PROJ_SRCS = $(OLD_PROJ)/$(SRCS_DIR)

OBJ_DIR = obj

LIB_DIR = lib

LIB = libft.a

SRCS_FILES = ft_main.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

O_SRCS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

GREY            = \033[0;30m
RED             = \033[0;31m
GREEN           = \033[0;32m
YELLOW          = \033[0;33m
BLUE            = \033[0;34m
FUCHSIA         = \033[0;35m
CYAN            = \033[0;36m
NC              = \033[0m

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c $(DEPS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_1) -I $(HEADER_2)

all: $(NAME)

$(NAME): $(SRCS) $(O_SRCS)
	$(MAKE) -C $(OLD_PROJ) all
	$(CC) $(CFLAGS) $(O_SRCS) $(OLD_PROJ)/$(LIB_DIR)/$(LIB) -o $(NAME)
