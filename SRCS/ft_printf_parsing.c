/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_parsing.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 13:39:26 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 18:48:18 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	printf_parsing(t_conv *t)
{
	t->flag = 'x';
	t->width = 0;
	t->precision = -1;
	t->neg = 0;
	if (t->format[t->i] == '%')
	{
		while (t->i != t->j - 1 && t->format[t->i])
		{
			printf_width(t);
			printf_precision(t);
			t->i++;
		}
		conversion_call(t);
		t->len = ft_strlen(t->to_print);
	}
	printf_output(t);
}

void	conversion_call(t_conv *t)
{
	if (t->conv_char == 's')
		t->to_print = va_arg(t->argp, char *);
	else if (t->conv_char == 'c')
		t->char_to_print = va_arg(t->argp, int);
	else if (t->conv_char == 'p')
		t->adress = va_arg(t->argp, void *);
	else if (ft_strchr("diuxX", t->conv_char))
		t->to_convert = va_arg(t->argp, int);
	if (t->conv_char == 'd' || t->conv_char == 'i')
		t->to_print = ft_itoa(t->to_convert);
	else if (t->conv_char == 'u')
		conversion_u(t);
	else if (t->conv_char == 'x')
		t->to_print = uitoa_base(t->to_convert, "0123456789abcdef");
	else if (t->conv_char == 'X')
		t->to_print = uitoa_base(t->to_convert, "0123456789ABCDEF");
	else if (t->conv_char == 'c')
		conversion_c(t);
	else if (t->conv_char == 'p')
		conversion_p(t);
	else if (t->conv_char == '%')
		conversion_perc(t);
}

void	printf_width(t_conv *t)
{
	if (((t->format[t->i] == '-' || t->format[t->i] == '0')
			&& (t->format [t->i + 1] != '-' && t->format[t->i + 1] != '0'))
			|| (t->format[t->i] > 47 && t->format[t->i] < 58)
			|| t->format[t->i] == '*')
	{
		if (t->format[t->i] == '-')
		{
			t->flag = '-';
			t->i++;
		}
		else if (t->format[t->i] == '0')
		{
			t->flag = '0';
			t->i++;
		}
		if (t->format[t->i] == '*')
		{
			t->width = va_arg(t->argp, int);
			t->i++;
		}
		else
			t->width = atoi_struc(t);
	}
}

void	printf_precision(t_conv *t)
{
	t->pswitch = 0;
	if (t->format[t->i] == '.' && ((t->format[t->i + 1] > 47 
					&& t->format[t->i + 1] < 58) || t->format[t->i + 1] == '*'))
	{
		t->pswitch = 1;
		t->i++;
		if (t->format[t->i] == '*')
		{
			t->precision = va_arg(t->argp, int);
			t->i++;
		}
		else
			t->precision = atoi_struc(t);
	}
}

void	printf_output(t_conv *t)
{
	if (t->to_print[0] == '-')
		t->neg = 1;
	if (t->neg == 1)
		t->plen = t->precision - t->len + 1;
	else
		t->plen = t->precision - t->len;
	int_precision_output(t);
	string_precision_output(t);
	if (t->pswitch == 1 && t->plen > 0)
		t->to_fill = t->width - t->precision;
	else
		t->to_fill = t->width - ft_strlen(t->to_print);
	int_width_output(t);
	string_width_output(t);
	char_width_output(t);
	perc_width_output(t);
	//printf("\nplen ---> %d\n to_fill ---> %d\n to_print ---> %s\n width ---> %d\n precision ---> %d\n len --->%d\n pswitch --->%d\n to_print ---> %s\n str ---> %sI\n i ---> %d\n j ---> %d\n conv_num ---> %d\n flag --->%c\n conv_char ---> %c\n t->i ---> %d\n t->format[i] ---> %c\n", t->plen, t->to_fill, t->to_print, t->width, t->precision, t->len, t->pswitch, t->to_print, t->str, t->i, t->j, t->conv_num, t->flag, t->conv_char, t->i, t->format[t->i]);
}
