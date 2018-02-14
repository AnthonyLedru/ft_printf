# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aledru <aledru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 16:42:45 by aledru            #+#    #+#              #
#*   Updated: 2018/01/17 21:55:47 by aledru           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

INCLUDE_FOLDERS := -I includes/ -I libft/includes/
SOURCES_FOLDER  := srcs/
OBJECTS_FOLDER  := objs/

vpath %.c srcs

FLAGS := -Wall -Wextra -Werror

SOURCES := \
		ft_printf.c \

OBJECTS := $(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER), $(SOURCES))

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

all: header $(NAME)

header:
	@printf "\n$(HEAD_COLOR)--------------------------------\n"
	@printf "$(HEAD_COLOR)---------- FT_PRINTF -----------\n"
	@printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"

$(NAME): $(OBJECTS)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@printf "$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@ar rcs $(NAME) $(OBJECTS)
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)"

objs/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE_FOLDERS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)ft_printf : Objects removed$(NO_COLOR)\n"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@printf "$(SILENT_COLOR)ft_printf : Binary removed $(NO_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re header
