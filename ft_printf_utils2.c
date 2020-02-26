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
		&& (t->to_conv == 0 || t->to_print[0] == '\0'))
		|| (t->to_print[0] == '\0' && t->conv_char == 's'))
	{
		if (t->width > 0)
			t->to_print = ft_strdup(" ");
		else if (t->width == 0)
			t->to_print = ft_strdup("");
	}
}

void	nul_char_conv(t_conv *t)
{
	if (!(t->to_print = ft_calloc(2, sizeof(char))))
		return ;
	t->to_print[0] = t->char_to_print;
	if (t->char_to_print == 0)
	{
		if (!(t->str = ft_calloc(2, sizeof(char))))
			return ;
		t->str[0] = t->char_to_print;
		t->c_zero = 1;
	}
}

void	nul_char_output(t_conv *t)
{
	if (t->char_to_print == 0 && t->width == 0)
	{
		t->to_fill--;
		t->ret_val++;
		t->plen = 1;
	}
	else if (t->char_to_print == 0 && t->width > 1)
	{
		t->to_fill--;
		free(t->to_print);
		t->fill_str = ft_strncat_mod(' ', t->to_fill, t->len);
		t->str = ft_strcat(t->fill_str, t->str, 2);
	}
}

void	get_string(t_conv *t)
{
	t->to_print = va_arg(t->argp, char *);
	if (t->to_print == NULL)
		t->to_print = "(null)";
}
