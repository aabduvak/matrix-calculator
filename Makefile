# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabduvak <abdulaziz.yosk@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 16:23:46 by aabduvak          #+#    #+#              #
#    Updated: 2022/11/29 17:40:14 by aabduvak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

BLACK			=	"\033[0;30m"
RED				=	"\033[0;31m"
GREEN			=	"\033[1;32m"
YELLOW			=	"\033[0;33m"
CYAN			=	"\033[0;35m"
BLUE			=	"\033[0;36m"
WHITE			=	"\033[0;37m"
END				=	"\033[0;0m"

# Files

SRCS			= $(shell find sources -type f -name "*.c")
OBJS			= $(SRCS:sources/%.c=sources/bin/%.o)

# Command and Flags

NAME			= matrix
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra

# Directories

INC				= ./includes/
BIN				= ./sources/bin/
LIB				= ./lib/.$(NAME)

# Rules

all : $(NAME)

$(LIB):
	@make -C ./lib

$(BIN):
	@mkdir $(BIN)

$(BIN)%.o: sources/%.c
	@mkdir -p $(shell dirname $@)
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $@ -I$(INC)

$(NAME): $(BIN) $(OBJS)
	@echo $(YELLOW) "Building... $(NAME)" $(END)
	@$(CC) $(OBJS) $(FRAMEWORK) -o $(NAME) $(LIBFT) $(MINILIBX)
	@echo $(GREEN) "$(NAME) created successfully!\n" $(END)

# $< input files
# $@ output files
# in makefile used to create oputput files in their subfolder

clean :
	@echo $(YELLOW) "Removing object files...$(NAME)" $(END)
	@$(RM) $(OBJS)
	@echo $(RED) "All files deleted successfully!\n" $(END)

fclean : clean
	@echo $(YELLOW) "Removing $(NAME)..." $(END)
	@$(RM) $(NAME)
	@$(RM) $(BIN)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

norm :
	@norminette includes/
	@norminette sources

re : fclean all

run : $(NAME)
	@./$(NAME) data/m1.mx data/m0.mx

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make            --------- compiles all *.c files and create libftprintf.a library"
	@echo "make clean      --------- cleans all *.o files in sources"
	@echo "make fclean 	   --------- cleans all *.o files in sources and libftprintf.a library"
	@echo "make re         --------- cleans all files and compiles again"
	@echo "make norm       --------- controls all *.c and *.h codes to norminette standart"
	@echo "make run        --------- compile and run program"
	@echo "make leaks      --------- checks all leaks in the program and creates output.file"

.PHONY: all clean fclean re run
