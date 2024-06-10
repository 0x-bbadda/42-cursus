/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:02:46 by bbadda            #+#    #+#             */
/*   Updated: 2024/01/11 17:30:03 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putnbr(int n);
int	ft_xbase16(unsigned long n, char c);
int	ft_unsigned_nbr(unsigned int n);
int	ft_putstr(char *str);
int	ft_putchar(char c);

#endif