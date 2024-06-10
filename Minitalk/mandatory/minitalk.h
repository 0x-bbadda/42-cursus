/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:21:12 by bbadda            #+#    #+#             */
/*   Updated: 2024/06/06 11:02:25 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

//---------------MANDATORY_FUNCTIONS------------------//
void		get_sing(int sign, siginfo_t *info, void *con);
void		converts_to_bits(int pid, unsigned char character);
int			converts_to_decimal(char *str);
//---------------UTILITS_FUNCTIONS------------------//
void		ft_putchar(char c);
size_t		ft_strlen(const char *str);
void		ft_putnbr(int n);
int			ft_atoi(const char *str);
void		__error(int x);

#endif