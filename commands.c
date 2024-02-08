#include "push_swap.h"

//frees tmp
// void delete_tmp(void *tmp)
// {
//     free(tmp);
// }

//lstdelone for push_swap
// void	ft_ps_delone(t_node *lst, void (*del)(void*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->nbr);
//     del(lst->index);
// 	free(lst);
// }

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

//turns tabs of argv into spaces
char	space(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (*str);
}

//checks if string is an int
int	check_int(char *str)
{
	int	i;
	int	ret_val;

	i = 0;
	ret_val = -1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			ret_val = 0;
		else
			ret_val = 1;
		i++;
	}
	return (ret_val);
}

//if duplicates -1 else 0
int	check_dup(char **argv_split)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv_split[i] != '\0')
	{
		i = ft_atoi(argv_split[i]);
		while (argv_split[j] != '\0')
		{
			j = i + 1;
			if (argv_split[j] == argv_split[i])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
