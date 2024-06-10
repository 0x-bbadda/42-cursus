/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 05:47:47 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/01 13:27:42 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst1;
	t_list	*tmp;

	if (lst == NULL || del == NULL)
		return ;
	lst1 = *lst;
	while (lst1 != NULL)
	{
		tmp = lst1->next;
		ft_lstdelone(lst1, del);
		lst1 = tmp;
	}
	*lst = NULL;
}
