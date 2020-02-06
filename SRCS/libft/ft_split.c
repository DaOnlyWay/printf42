/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 14:50:27 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 16:55:56 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strlenmod(const char *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

static int		ft_ccount(const char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 1;
	while (s[i] != 0)
	{
		if (s[i] == c)
		{
			while (s[i + 1] == c)
				i++;
			if (s[i + 1])
				count++;
		}
		i++;
	}
	if (count == 1 && s[0] == c)
		return (0);
	return (count);
}

static char		**ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (tab);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		len;
	int		strings;

	i = 0;
	j = 0;
	tab = NULL;
	if (!s || !s[0] || (!(strings = ft_ccount(s, c) + 1))
		|| !(tab = ft_calloc(strings + 1, sizeof(tab))))
		return (tab = ft_calloc(1, sizeof(tab)));
	while (--strings > 0)
	{
		if (s[i] != c)
		{
			i += len = ft_strlenmod(s, c, i);
			if (!(tab[j++] = ft_substr(s, i - len, len, 0)))
				return (ft_free_tab(tab));
		}
		while (s[i] == c)
			i++;
	}
	return (tab);
}
