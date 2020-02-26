/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:07:42 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 17:19:55 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strdup(const char *src);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s,
		unsigned int start, size_t len, int count);
char	*ft_strjoin(char *s1, char *s2, int count);
char	*ft_strtrim(char const *s1, char const *set, int count);
int		ft_cmpchar(const char *s1, const char *set, int start, int pos);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char	*itoa_base(int n, char *base);
char	*uitoa(unsigned int n);
void	ft_putstr(char *str);
char	*ft_strcat(char *dest, char *src, int count);
char	*ft_strncat_mod(char src, int nb, int len);
char	*ft_strcat_mod(char *s1, char *s2);
void	*ft_realloc_mod(char fill, void *ptr, size_t size, int count);
char	*uitoa_base(unsigned long n, char *base);
#endif
