/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:06:33 by bbadda            #+#    #+#             */
/*   Updated: 2024/09/07 09:42:08 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	__strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	__bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)(s + n)) = 0;
}

void	*__calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(size * count);
	if (!res)
		return (0);
	__bzero(res, size * count);
	return (res);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned long long	r;

	r = 0;
	s = 1;
	i = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		s = -s;
	if ((*str == '+' || *str == '-'))
		str++;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			__error(1);
		i++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + (*str - 48);
		str++;
	}
	return (r * s);
}

int	cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (__strlen(s1) != __strlen(s2))
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
