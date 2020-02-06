/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 15:52:10 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 01:10:49 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t dest_len;
	size_t src_len;
	size_t j;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (dest_len >= size || size == 0)
		return (src_len + size);
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (dest_len + src_len);
}
