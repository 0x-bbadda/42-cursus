/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 04:25:44 by bbadda            #+#    #+#             */
/*   Updated: 2024/03/23 04:11:02 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int			ft_isdigit(int nb);
int			ft_isalnum(int k);
int			ft_isascii(int a);
int			ft_isprint(int p);
int			ft_toupper(int c);
int			ft_tolower(int c);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
void		*ft_memset(void	*str, int c, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dst_l);
size_t		ft_strlcpy(char *dst, const char *src, size_t dst_l);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_strncmp(const	char *str1, const char *str2, size_t n);
char		*ft_strnstr(const char *b_str, const char *l_str, size_t len);
int			ft_atoi(const char *str);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *str, char const *set);
char		**ft_split(char const *str1, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *str, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
//-----------------get_next_line----------------------------------------//
char		*get_next_line(int fd);
size_t		__lenline(char *stow);
char		*__dupline(char *src);
char		*__linechr(char *str, int c);
char		*__joinline(char *s1, char *s2);
char		*__subline(char *str, unsigned int start, size_t len);
char		*__linesub(char *stow, unsigned int start, size_t len);

#endif