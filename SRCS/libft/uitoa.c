/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   uitoa.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 19:09:10 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 19:27:28 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static inline int	ft_string_size(unsigned int n)
{
	int i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*uitoa(unsigned int n)
{
	char	*dest;
	int		len;

	dest = NULL;
	len = ft_string_size(n);
	if (!(dest = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	dest[len] = 0;
	len--;
	while (n != 0)
	{
		dest[len--] = n % 10 + '0';
		n /= 10;
	}
	return (dest);
}
