/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:25:09 by ccroissa          #+#    #+#             */
/*   Updated: 2021/01/25 16:17:39 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

void	printf_parsing(t_conv *t)
{
	if (t->format[t->i] == '%')
	{
		while (t->i != t->j - 1 && t->format[t->i])
		{
			printf_width(t);
			printf_precision(t);
			if (t->i == t->j - 1)
				break ;
			t->i++;
		}
		conversion_call(t);
		t->len = ft_strlen(t->to_print);
	}
	printf_output(t);
	if (ft_strchr("di", t->conv_char) && ft_strchr("-x", t->flag)
		&& t->err == 0 && (t->err = 1))
		free(t->to_print);
}

void	conversion_call(t_conv *t)
{
	if (t->conv_char == 's')
		get_string(t);
	else if (t->conv_char == 'c')
		t->char_to_print = (unsigned char)va_arg(t->argp, int);
	else if (t->conv_char == 'p')
		t->adress = va_arg(t->argp, void *);
	else if (ft_strchr("diuxX", t->conv_char))
		t->to_conv = va_arg(t->argp, int);
	if (t->conv_char == 'd' || t->conv_char == 'i')
		conversion_d(t);
	else if (t->conv_char == 'u')
		conversion_u(t);
	else if (t->conv_char == 'x')
		conversion_x(t);
	else if (t->conv_char == 'X')
		conversion_xup(t);
	else if (t->conv_char == 'c')
		conversion_c(t);
	else if (t->conv_char == 'p')
		conversion_p(t);
	else if (t->conv_char == '%')
		conversion_perc(t);
	empty_string(t);
}

void	printf_width(t_conv *t)
{
	if ((t->format[t->i] == '-' || t->format[t->i] == '0')
			|| (t->format[t->i] > 47 && t->format[t->i] < 58)
			|| t->format[t->i] == '*')
	{
		if (t->format[t->i] == '-')
		{
			t->flag = '-';
			t->i++;
			if (t->format[t->i] == '0')
				t->i++;
		}
		else if (t->conv_char == '%' && t->format[t->i - 1] == '-')
			t->flag = '-';
		if (t->format[t->i] == '0' && (t->conv_char != '%'
			&& t->format[t->i - 1] != '-'))
		{
			t->flag = '0';
			t->i++;
			if (t->format[t->i] == '-' && (t->flag = '-'))
				t->i++;
		}
		width_arg(t);
	}
}

void	printf_precision(t_conv *t)
{
	if (t->format[t->i] == '.')
	{
		if (ft_strchr("diuxXs%", t->format[t->i + 1]))
			t->prec = 0;
		t->pswitch = 1;
		t->i++;
		if (t->format[t->i] == '*')
		{
			t->prec = va_arg(t->argp, int);
			t->i++;
			if (t->prec < 0)
				t->pswitch = 0;
		}
		else
			t->prec = atoi_struc(t);
	}
}

void	printf_output(t_conv *t)
{
	if (t->to_print[0] == '-')
		t->neg = 1;
	if (t->neg == 1 && t->pswitch == 1)
		t->plen = t->prec - t->len + 1;
	else if (t->pswitch == 1)
		t->plen = t->prec - t->len;
	int_precision_output(t);
	string_precision_output(t);
	if ((t->pswitch == 1 && t->prec > t->len && ft_strchr("diuxX", t->conv_char)
		&& t->neg != 1) ||
		(t->pswitch == 1 && t->prec < t->len && t->conv_char == 's'))
		t->to_fill = t->width - t->prec;
	else if (t->pswitch == 1 && t->prec >= t->len
		&& ft_strchr("diuxX", t->conv_char) && t->neg == 1)
		t->to_fill = t->width - t->prec - 1;
	else
		t->to_fill = t->width - t->len;
	int_width_output(t);
	string_width_output(t);
	char_width_output(t);
	address_width_output(t);
	perc_width_output(t);
}
