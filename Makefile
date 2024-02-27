################################################################################
#								CONSTANTS									   #
################################################################################
CC = gcc
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror -g
LIBS = libft.h push_swap.h
LIBFT_PATH = ./Libft
LIBFT := $(LIBFT_PATH)/libft.a
LDFLAGS = -L $(LIBFT_PATH) -lft

vpath %.h $(LIBFT_PATH) .

################################################################################
#							PUSH_SWAP MANDATORY								   #
################################################################################

NAME = push_swap

SRC =	p_main.c\
		checks.c\
		commands_pa_pb.c\
		commands_sa_sb_ss.c\
		commands_ra_rb_rr.c \
		commands_rra_rrb_rrr.c\
		index.c\
		initialise.c\
		sorting.c\
		square_root.c\
		assignment.c\
		3_sort.c\
		frees.c

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ)#########################
	@$(CC) $(DEBUG) $^ $(LDFLAGS) -o $@

$(OBJ) : %.o : %.c
	@$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) $< -o $@

clean :
	@rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean : clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@echo "Removed $(NAME)"
	@make -C $(LIBFT_PATH) fclean
#	@echo "Removing libft.a"
#	@rm -f libft.a
#	@echo "Removed libft.a"
#	@echo "Removing libft.h"
#	@rm -f libft.h
#	@echo "Removed libft.h"
#	@echo "Cleaning $(LIBFT_PATH)"
#	@cd $(LIBFT_PATH) && make fclean
#	@echo "Cleaned $(LIBFT_PATH)"
#	@rm -f a.out

re : fclean all

################################################################################
#									LIBFT									   #
################################################################################

$(LIBFT):
	@echo "Building libft..."
	@+make -C $(LIBFT_PATH) -B --no-print-directory

#								#TODO na ta prostheso epano#
################################################################################
#								TESTS AND NOTES								   #
################################################################################

# executable : $(NAME)
# 	@$(CC) $(DEBUG) $(CFLAGS) *.c -L. -lft -o a.out
#	@$(CC) $(DEBUG) $(CFLAGS) *.c -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft -o a.out
#windows

.PHONY :
	all clean fclean re
