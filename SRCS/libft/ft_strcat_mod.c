/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat_mod.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/11 15:48:12 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 16:16:35 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_mod(char *s1, char *s2)
{
	int i;
	int j;
	char *dest;

	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	i = 0;
	while (s1[i++])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	free (s2);
	return (dest);
}
