/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:11 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 16:24:20 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	conversion_u(t_conv *t)
{
	unsigned int	temp;

	temp = t->to_conv;
	t->to_print = uitoa(temp);
}

void	conversion_c(t_conv *t)
{
	t->to_print = NULL;
	if (t->width > 0)
	{
		if (!(t->to_print = ft_calloc(t->width + 1, sizeof(char))))
			return ;
		t->to_print[0] = t->char_to_print;
	}
	else
	{
		t->str = NULL;
		if (!(t->str = ft_calloc(2, sizeof(char))) ||
		!(t->to_print = ft_calloc(2, sizeof(char))))
			return ;
		t->to_print[0] = t->char_to_print;
		t->str[0] = t->char_to_print;
	}
}

void	conversion_p(t_conv *t)
{
	unsigned long num;

	num = (unsigned long)t->adress;
	t->to_print = uitoa_base((unsigned long)num, "0123456789abcdef");
	t->to_print = ft_strjoin("0x", t->to_print, 1);
}

void	conversion_perc(t_conv *t)
{
	t->to_print = NULL;
	if (!(t->to_print = ft_calloc(2, sizeof(char))))
		return ;
	t->to_print[0] = '%';
}
