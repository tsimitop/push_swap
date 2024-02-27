/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_root.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:35 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/27 16:52:01 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	square_root(int number)
{
	double	x;
	double epsilon;

	x = number;
	epsilon = 0.000001;
	while ((x * x - number) > epsilon)
		x = 0.5 * (x + number / x);
	return (x);
}
