/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 15:42:13 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 17:12:21 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int count)
{
	char	*str;
	int		i;
	int		n;

	n = 0;
	if (!s1 || !s2)
		return (0);
	i = strlen(s1) + strlen(s2);
	if (!(str = ft_calloc(sizeof(char), i + 1)))
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[n])
	{
		str[i] = s2[n];
		n++;
		i++;
	}
	if (count == 1)
		free (s2);
	return (str);
}
