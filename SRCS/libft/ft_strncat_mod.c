/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat_mod.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 14:56:33 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 15:31:21 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat_mod(char src, int nb, int len)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = ft_calloc(nb + len + 1, sizeof(char*))))
		return (NULL);
	while (nb > 0)
	{
		dest[i++] = src;
		nb--;
	}
	return (dest);
}
