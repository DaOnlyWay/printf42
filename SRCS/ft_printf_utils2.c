/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:10:30 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 16:25:41 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	width_arg(t_conv *t)
{
	if (t->format[t->i] == '*')
	{
		t->width = va_arg(t->argp, int);
		t->i++;
		if (t->width < 0)
		{
			t->flag = '-';
			t->width *= -1;
		}
	}
	else
		t->width = atoi_struc(t);
}

void	empty_string(t_conv *t)
{
	if ((t->prec == 0 && ft_strchr("diuxXs", t->conv_char)
		&& (t->to_convert == 0 || t->to_print[0] == '\0'))
		|| (t->to_print[0] == '\0' && t->conv_char == 's'))
	{
		if (t->width > 0)
			t->to_print = ft_strdup(" ");
		else if (t->width == 0)
			t->to_print = ft_strdup("");
	}
}
