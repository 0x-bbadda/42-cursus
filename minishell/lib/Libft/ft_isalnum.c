/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:13:45 by asalmi            #+#    #+#             */
/*   Updated: 2024/09/18 20:01:50 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int str)
{
	if ((str >= 'a' && str <= 'z') || (str >= 'A' && str <= 'Z'))
		return (1);
	else if (str >= '0' && str <= '9')
		return (1);
	else
		return (0);
}
