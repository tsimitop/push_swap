#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "/workspaces/push_swap/Libft/libft.h"
# include "/Users/tsimitop/Documents/Testing/Push_swap/Libft/libft.h"

typedef struct	t_stack
{
	t_node		*head_A;
	t_node		*head_B;
}				t_stack;

/*struct nodes*/
typedef struct	t_node
{
	char			*init_inp;
	int				*nbr;
	int				*index;
	struct t_node	*next;
	struct t_node	*prev;
}				t_node;

/*utils*/
void	delete_tmp(void *tmp);
void	ft_ps_delone(t_node *lst, void (*del)(void*));
char	space(char *str);

/*commands*/



#endif
