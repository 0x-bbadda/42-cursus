/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:48:28 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/02 15:49:42 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a, t_list *tmp)
{
	int	tmp2;

	tmp2 = tmp->content;
	tmp->content = stack_a->content;
	stack_a->content = tmp2;
	write(1, "sa\n", 3);
}

void	sb(t_list *stack_b, t_list *tmp)
{
	int	tmp2;

	tmp2 = tmp->content;
	tmp->content = stack_b->content;
	stack_b->content = tmp2;
	write(1, "sb\n", 3);
}

// void	ss(t_list *stack_a, t_list *stack_b)
// {
// 	sa(stack_a);
// 	sb(stack_b);
// }