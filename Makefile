# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/11 10:20:01 by afoulqui          #+#    #+#              #
#    Updated: 2021/01/11 16:28:59 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- #
#	  VARIABLES		#
# ----------------- #

EXEC        =	a.out

NAME		=	libasm.a

HEADER		=	include/libasm.h

SRC_DIR		=	srcs/
OBJ_DIR		=	objs/

vpath %.s $(foreach dir, $(SRC_DIR), $(dir):)

SRC			= 	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.s), $(notdir $(file))))
OBJ 		=	$(addprefix $(OBJ_DIR), $(SRC:%.s=%.o))

# ----------------- #
#	 COMPILATION	#
# ----------------- #

CC = 		gcc -no-pie

FLAG =		-Wall -Werror -Wextra

# ----------------- #
#	  FUNCTIONS		#
# ----------------- #

$(OBJ_DIR)%.o: %.s $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			@echo "\033[32mCompilation of ... $(foreach file, $< , $(notdir $<))\033[0m"
			@nasm -f elf64 -o $@ -s $^
			
$(NAME):	$(OBJ) 		
			@ar rc ${NAME} ${OBJ}
			@echo "\n\033[32mlibasm.a ... Done\033[0m\n"
	
all:		${NAME}

show:
			@echo "SRC_DIR : $(SRC_DIR)\n"
			@echo "HEADER : $(foreach file, $(HEADER),\n\t$(file))\n"
			@echo "SRC :$(foreach file, $(SRC),\n\t$(file))\n"
			@echo "OBJ :$(foreach file, $(OBJ),\n\t$(file))\n"

test:		$(NAME)
			@$(CC) $(FLAG) -I include tests/*.c libasm.a
			@touch tests/txt_files/write.txt
			@touch tests/txt_files/ft_write.txt
			@echo "\n\033[32mtest ... Done\033[0m\n"
			
run:		test
			./$(EXEC)

# ----------------- #
# 		CLEAN		#
# ----------------- #

clean:
			@rm -rf $(OBJ_DIR)
			@echo "\n\033[36;1m ------>>  clean\033[0m\n"

fclean:		clean
			@rm -f $(NAME)
			@rm -f $(EXEC)
			@rm -f tests/txt_files/write.txt
			@rm -f tests/txt_files/ft_write.txt
			@echo "\033[36;1m ------>> fclean\033[0m\n"

re:			fclean all

.PHONY: 	all clean fclean re test run
