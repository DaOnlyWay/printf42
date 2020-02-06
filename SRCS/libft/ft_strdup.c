/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 17:40:38 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 17:50:55 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tempsrc;
	char	*dest;
	int		i;

	tempsrc = (char *)src;
	i = 0;
	dest = NULL;
	while (tempsrc[i])
		i++;
	if (!(dest = malloc(sizeof(*dest) * (i + 1))))
		return (dest = ft_calloc(1, sizeof(char)));
	i = 0;
	while (tempsrc[i])
	{
		dest[i] = tempsrc[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
