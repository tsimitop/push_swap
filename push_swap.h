#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "/workspaces/PUSH/Libft/libft.h"
// # include "/Users/tsimitop/Documents/Testing/PUSH/Libft/libft.h"
# include "libft.h"

/*struct nodes*/
typedef struct	t_node
{
	// char			*init_inp;
	int				nbr;
	int				index;
	struct t_node	*next;
	struct t_node	*prev;
}				t_node;

typedef struct	t_stack
{
	t_node		*head;
	// t_node		*head_B;
	// size_t		size; //how many in the stack
}				t_stack;

/*utils*/
// void	delete_tmp(void *tmp);
// void	ft_ps_delone(t_node *lst, void (*del)(void*));
char	space(char *str);
int		check_int(char *str);
int		check_dup(char **argv_split)

/*commands*/



#endif
