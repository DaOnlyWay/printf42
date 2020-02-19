/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:30 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/19 16:26:49 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_printf(const char *format, ...)
{
	t_conv	t;

	t.j = 0;
	t.i = 0;
	t.conv_num = 0;
	t.ret_val = 0;
	t.format = format;
	va_start(t.argp, format);
	conv_number(&t);
	printf_loop(&t);
	while ((size_t)t.j < ft_strlen(t.format))
	{
		write(1, &t.format[t.j++], 1);
		t.ret_val++;
	}
	va_end(t.argp);
	return (t.ret_val);
}

void	printf_loop(t_conv *t)
{
	while (t->conv_num > 0 && t->format[t->j] != '\0')
	{
		t->free_switch = 0;
		get_conv(t);
		if (t->conv_char == '%')
			t->conv_num--;
		printf_parsing(t);
		ft_putstr(t->str);
		if (t->conv_char != '%')
			t->i++;
		if (t->to_fill > 0)
			t->ret_val += t->width;
		else
			t->ret_val += ft_strlen(t->str);
		if (t->free_switch == 0)
			free(t->str);
		if ((t->plen > 0) && ft_strchr("diuxX", t->conv_char))
			free(t->to_print);
		t->conv_num--;
		text_print(t);
	}
}

void	text_print(t_conv *t)
{
	if (t->conv_num > 0)
	{
		while (t->format[t->j] != '%')
		{
			write(1, &t->format[t->j++], 1);
			t->i++;
			t->ret_val++;
		}
	}
}
