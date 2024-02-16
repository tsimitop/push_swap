################################################################################
#								CONSTANTS									   #
################################################################################
CC = gcc
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror
LIBS = libft.h push_swap.h
LIBFT_PATH = $(shell pwd)/Libft

################################################################################
#							PUSH_SWAP MANDATORY								   #
################################################################################

NAME = push_swap.a

SRC =	p_main.c\
		checks.c\
		commands_pa_pb.c\
		commands_sa_sb_ss.c\
		commands_ra_rb_rr.c \
		commands_rra_rrb_rrr.c\
		index.c\
		initialise.c

OBJ = $(SRC:.c=.o)

all : libft $(NAME)

$(NAME) : libft $(OBJ) #########################
	@ar rc $(NAME) $(OBJ)

$(OBJ) : %.o : %.c push_swap.h $(LIBFT_PATH)/libft.h
	@$(CC) -c $(CFLAGS) -I$(LIBFT_PATH) $< -o $@

clean :
	@rm -f $(OBJ)
	@cd $(LIBFT_PATH) && make clean

fclean : clean
	@echo "Removing $(NAME)"
	@rm -f $(NAME)
	@echo "Removed $(NAME)"
	@echo "Removing libft.a"
	@rm -f libft.a
	@echo "Removed libft.a"
	@echo "Removing libft.h"
	@rm -f libft.h
	@echo "Removed libft.h"
	@echo "Cleaning $(LIBFT_PATH)"
	@cd $(LIBFT_PATH) && make fclean
	@echo "Cleaned $(LIBFT_PATH)"
#	@rm -f a.out

re : fclean all

################################################################################
#									LIBFT									   #
################################################################################

libft:
	@echo "Building libft..."
	@cd $(LIBFT_PATH) && make
	@echo "Built libft"

#								#TODO na ta prostheso epano#
################################################################################
#								TESTS AND NOTES								   #
################################################################################

executable : $(NAME)
	@$(CC) $(DEBUG) $(CFLAGS) *.c -L. -lft -o a.out
#	@$(CC) $(DEBUG) $(CFLAGS) *.c -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft -o a.out
#windows

.PHONY :
	all clean fclean re libft executable
