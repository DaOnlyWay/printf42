/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 18:22:32 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 01:04:09 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dstalt;
	unsigned char		*srcalt;
	size_t				i;

	if (!dst && !src)
		return (0);
	i = 0;
	dstalt = (unsigned char *)dst;
	srcalt = (unsigned char *)src;
	if (dstalt > srcalt)
	{
		while (len--)
			dstalt[len] = srcalt[len];
		return (dstalt);
	}
	while (i < len)
	{
		dstalt[i] = srcalt[i];
		i++;
	}
	return (dstalt);
}
