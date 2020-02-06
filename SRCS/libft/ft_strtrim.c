/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 14:43:25 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:55:24 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	int		len;
	char	*dest;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	start = ft_cmpchar(s1, set, 0, 1);
	end = ft_cmpchar(s1, set, len - 1, -1);
	if (start == len || !(dest = ft_substr(s1, start, end + 1 - start, 0)))
		return (dest = ft_calloc(1, sizeof(*dest)));
	return (dest);
}
