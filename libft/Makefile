# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aledru <aledru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 14:26:59 by aledru            #+#    #+#              #
#*   Updated: 2018/02/16 17:15:40 by aledru           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME := libft.a

INCLUDE_FOLDERS := -I includes/
SOURCES_FOLDER := srcs/
OBJECTS_FOLDER := objs/

vpath %.c srcs

FLAGS := -Wall -Werror -Wextra

SOURCES := \
			ft_isdigit.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_atoi.c \
			ft_memalloc.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memset.c \
			ft_strcpy.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c

OBJECTS := $(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER), $(SOURCES))

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

HEADER_PRINTED = NO

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "\n$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@ar rcs $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)\n"

objs/%.o: %.c
	@if [ "$(HEADER_PRINTED)" = "NO" ]; then \
		printf "\n$(HEAD_COLOR)--------------------------------\n"; \
		printf "$(HEAD_COLOR)------------ LIBFT -------------\n"; \
		printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"; \
		$(eval HEADER_PRINTED = YES) \
	fi
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE_FOLDERS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)libft : Objects removed$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(SILENT_COLOR)libft : Library removed$(NO_COLOR)\n"

re: fclean all

.PHONY: all re clean fclean header
