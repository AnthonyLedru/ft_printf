# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aledru <aledru@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 16:42:45 by aledru            #+#    #+#              #
#*   Updated: 2018/02/16 21:05:24 by aledru           ###   ########.fr       *#
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
		error.c \
		env.c \
		env_setters.c \
		put.c \
		parser.c \
		cast.c \
		conversion_selector.c \
		string_conversion.c \
		number_conversion.c \
		char_conversion.c \
		base_converter.c \

OBJECTS := $(SOURCES:.c=.o)

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER), $(SOURCES))

NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
HEAD_COLOR   := \x1b[32;01m
SILENT_COLOR := \x1b[30;01m

HEADER_PRINTED := NO

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libft/ -s
	@cp libft/libft.a ./$(NAME)
	@printf "\n$(SILENT_COLOR)Compiling $(NAME)...$(NO_COLOR)"
	@ar rcs $(NAME) $(OBJECTS)
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)"

objs/%.o: %.c
	@if [ "$(HEADER_PRINTED)" = "NO" ]; then \
		printf "\n$(HEAD_COLOR)--------------------------------\n"; \
		printf "$(HEAD_COLOR)---------- FT_PRINTF -----------\n"; \
		printf "$(HEAD_COLOR)--------------------------------$(NO_COLOR)\n\n"; \
		$(eval HEADER_PRINTED = YES) \
	fi
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDE_FOLDERS) -c $< -o $@
	@printf "$(notdir $<) "
	@printf "$(OK_COLOR)✓$(NO_COLOR)\n"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)ft_printf : Objects removed$(NO_COLOR)\n"

fclean:
	@make -C libft/ fclean
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(SILENT_COLOR)ft_printf : Objects removed$(NO_COLOR)\n"
	@rm -f $(NAME)
	@printf "$(SILENT_COLOR)ft_printf : Binary removed $(NO_COLOR)\n"

re: fclean all

exec: printf

printf: $(OBJECTS)
	@make -C libft/ -s
	@printf "\n$(SILENT_COLOR)Compiling binary...$(NO_COLOR)"
	@$(CC) -w libft/libft.a $(SOURCES) main.c $(INCLUDE_FOLDERS)
	@printf " $(OK_COLOR)Done ✓$(NO_COLOR)\n"
	@printf "$(OK_COLOR)Result with main.c : $(NO_COLOR)\n"
	@./a.out | cat -e



.PHONY: all clean fclean re header
