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
PARAMS			= data/m1.mx data/m0.mx
CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -pthread
TFLAGS			= -g -lpthread

BIN				= ./sources/bin/
LOG				= output.log

# Rules

all : $(NAME)

$(BIN):
	@mkdir $(BIN)

$(BIN)%.o: sources/%.c
	@mkdir -p $(shell dirname $@)
	@echo $(YELLOW) "Compiling..." $< $(END)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BIN) $(OBJS)
	@echo $(YELLOW) "Building... $(NAME)" $(END)
	@$(CC) $(OBJS) -o $(NAME) -pthread
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
	@$(RM) $(LOG)
	@echo $(RED) "$(NAME) deleted successfully!\n" $(END)

re : fclean all

run : $(NAME)
	@./$(NAME) $(PARAMS)
	@bash ./config.sh

test: $(NAME)
	@valgrind --log-file=$(LOG) --tool=helgrind ./$(NAME) $(PARAMS)
	@cat $(LOG)

leaks: $(NAME)
	@valgrind --log-file=$(LOG) --leak-check=yes --tool=memcheck ./$(NAME) $(PARAMS) 
	@cat $(LOG)

help :
	@echo "------------------------------------ <<HELP COMMAND>> ------------------------------------"
	@echo ""
	@echo "make            --------- compiles all *.c files and create libftprintf.a library"
	@echo "make clean      --------- cleans all *.o files in sources"
	@echo "make fclean 	   --------- cleans all *.o files in sources and libftprintf.a library"
	@echo "make re         --------- cleans all files and compiles again"
	@echo "make run        --------- compile and run program"
	@echo "make leaks      --------- checks all leaks in the program and creates output.file"

.PHONY: all clean fclean re run
