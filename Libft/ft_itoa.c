/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 09:36:23 by bbadda            #+#    #+#             */
/*   Updated: 2023/12/31 10:01:54 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*condition(int n)
{
	char	*str;

	if (n == 0)
	{
		str = (char *)malloc(2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	return (0);
}

static char	*get_str(char *str, int s, int n)
{
	while (n < 0) 
	{
		str[0] = '-';
		n = -n;
		str[s] = (n % 10) + 48;
		n = n / 10;
		s--;
	}
	while (n > 0) 
	{
		str[s] = (n % 10) + 48;
		n = n / 10;
		s--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		str = condition(n);
	else
	{
		s = size(n);
		str = (char *)malloc(sizeof(char) * (s + 1));
		if (str == NULL)
			return (NULL);
		str[s] = '\0';
		s--;
		str = get_str(str, s, n);
	}
	return (str);
}
