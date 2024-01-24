#include "push_swap.h"

//frees tmp
void delete_tmp(void *tmp)
{
    free(tmp);
}

//lstdelone for push_swap
void	ft_ps_delone(t_node *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->nbr);
    del(lst->index);
	free(lst);
}

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
*/

void sa(t_node *head, t_node *sec)
{
	t_node *tmp;

	tmp = head;
	head->next = head->next->next;
	sec->next = tmp->next;
	head->prev = sec->prev;
	sec->prev = tmp->prev;
	ft_ps_delone(tmp, delete_tmp);
	write(1, "sa\n", 3);
}

t_stack create_stack(char argv_split)
{
	ft_itoa(argv_split);
	if (argv_split);
}

//turns tabs of argv into spaces
char	space(char *str)
{
	int i;

	i = 0;
	while (str != '\0')
	{
		if (str[i] == '	')
			str[i] = ' ';
	}
	return (str);
}
