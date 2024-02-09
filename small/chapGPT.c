#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	t_node
{
	int				nbr;
	int				index;
	struct t_node	*next;
	struct t_node	*prev;
}				t_node;

typedef struct	t_stack
{
	t_node		*head;
}				t_stack;

void ft_ps_delone(t_node *node, void (*del)(t_node *));

void delete_tmp(t_node *node) {
    free(node);
}

void sa(t_stack *stack)
{
    if (stack->head == NULL || stack->head->next == NULL) {
        // Do nothing if there is only one or no elements
        return;
    }

    t_node *first = stack->head;
    t_node *second = first->next;

    // Swap the first two elements
    first->next = second->next;
    second->next = first;

    if (first->next != NULL) {
        first->next->prev = first;
    }
    second->prev = first->prev;
    first->prev = second;

    stack->head = second; // Update the head of the stack

    ft_ps_delone(first, delete_tmp);

    write(1, "sa\n", 3);
}

int main(int argc, char **argv)
{
    t_stack A_stack;
    t_node *temp = NULL;

    A_stack.head = NULL;

    if (argc == 2)
    {
        int i = 0;
        int digit;

        // Process input arguments
        // ...

        while (argv_split[i])
        {
            if (check_int(argv_split[i]) == 0 && check_dup(argv_split[i]) == 0)
            {
                digit = ft_atoi(argv_split[i]);

                // Create a new node
                t_node *new_node = (t_node *)malloc(sizeof(t_node));
                new_node->nbr = digit;
                new_node->next = NULL;
                new_node->prev = NULL;

                if (A_stack.head == NULL)
                {
                    A_stack.head = new_node;
                }
                else
                {
                    // Add the new node to the front of the linked list
                    new_node->next = A_stack.head;
                    A_stack.head->prev = new_node;
                    A_stack.head = new_node;
                }

                i++;
            }
            else
            {
                // Handle errors or exit appropriately
                exit(1);
            }
        }
        // Free allocated memory
        // ...

        // Example usage of the sa function
        sa(&A_stack);
    }

    return 0;
}