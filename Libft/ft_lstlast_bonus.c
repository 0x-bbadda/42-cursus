/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 02:35:03 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/01 13:28:39 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (!lst)
		return (NULL);
	i = 1;
	while (lst->next) 
	{
		lst = lst->next;
		i++;
	}
	return ((t_list *)lst);
}
