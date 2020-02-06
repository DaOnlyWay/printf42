/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/18 17:05:33 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 13:00:04 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int				i;
	char			*dest;
	int				len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (len == 0)
		len = 1;
	i = 0;
	if (!(dest = ft_calloc((len + 1), sizeof(char))))
		return (0);
	while (s[i])
	{
		dest[i] = (*f)(i, s[i]);
		i++;
	}
	return (dest);
}
