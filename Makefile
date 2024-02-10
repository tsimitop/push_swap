################################################################################
#								CONSTANTS									   #
################################################################################
CC = gcc
DEBUG = -g
CFLAGS = -Wall -Wextra -Werror
LIBS = libft.h push_swap.h

################################################################################
#							PUSH_SWAP MANDATORY								   #
################################################################################

NAME = push_swap.a

SRC =	p_main.c\
		checks.c\
		commands_pa_pb.c\
		commands_sa_sb_ss.c\
		commands_ra_rb_rr.c \
		commands_rra_rrb_rrr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : libft $(OBJ) #########################
	@ar rc $(NAME) $(OBJ)

$(OBJ) : %.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@rm -f libft.a
	@rm -f libft.h
	@rm -f a.out
	@cd Libft && make fclean

re : fclean all

################################################################################
#									LIBFT									   #
################################################################################

# LIBFT1 = ./Libft/libft.a
# LIBFT_OBJ_DIR = Libft/obj/
# LIBFT_SRC_DIR = Libft/

# $(LIBFT_OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c
# 	@mkdir -p $(LIBFT_OBJ_DIR)
# 	$(CC) $(CFLAGS) -c $< -o $@
libft:
	@cd Libft && make
# re_libft:
# 	@cd Libft && make re
# clean_libft:
# 	@cd Libft && make clean
# fclean_libft: clean_libft
# 	@cd Libft && make fclean
#								#TODO na ta prostheso epano#
################################################################################
#								TESTS AND NOTES								   #
################################################################################

executable : $(NAME)
	@$(CC) $(DEBUG) $(CFLAGS) *.c -L. -lft -o a.out

.PHONY :
	all clean fclean re libft executable
