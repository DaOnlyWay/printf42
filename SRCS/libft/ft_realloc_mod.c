/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc_mod.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 16:11:22 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:15:22 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc_mod(char fill, void *ptr, size_t size, int count)
{
	size_t i;
	char *dst;

	i = ft_strlen(ptr);
	if (!ptr || !(dst = ft_calloc(sizeof(char), size)))
		return (NULL);
	if (size < i)
		size = i;
	ft_memcpy(dst, ptr, i);
	while (i < size - 1)
		dst[i++] = fill;
	if (count == 1)
		free (ptr);
	return (dst);
}
