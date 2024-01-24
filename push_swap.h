#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*commands*/


/*struct nodes*/
typedef struct	t_node
{
	int				*nbr;
	int				*index;
	struct t_node	*next;
	struct t_node	*prev;
}				t_node;

#endif
