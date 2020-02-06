/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf_utils.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/10 06:38:00 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:36:35 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	get_conv(t_conv *t)
{
	while (t->format[t->j] != '%' && t->format[t->i] != 0)
	{
		write(1, &t->format[t->j], 1);
		t->j++;
		t->i++;
	}
	while(t->format[t->j++])
		if (ft_strchr("cspiudxX%", t->format[t->j]))
			break;
	t->conv_char = t->format[t->j];
	t->j++;
}

void	conv_number(t_conv *t)
{
	int j;

	j = 0;
	while (t->format[j] != '\0')
	{
		if (t->format[j] == '%')
			t->conv_num++;
		j++;
	}
}

int		atoi_struc(t_conv *t)
{
	int	sign;
	int result;

	result = 0;
	sign = 1;
	while ((t->format[t->i] == '\t') || (t->format[t->i] == '\n')
			|| (t->format[t->i] == '\v') || (t->format[t->i]== '\f')
			|| (t->format[t->i]  == '\r') || (t->format[t->i] == ' '))
		t->i++;
	while (t->format[t->i]  == '-' || t->format[t->i] == '+')
	{
		if (t->format[t->i] == '-')
			sign = (sign * (-1));
		if (t->format[t->i + 1] == '-' || t->format[t->i + 1] == '+')
			return (0);
		t->i++;
	}
	while (t->format[t->i] >= '0' && t->format[t->i] <= '9')
	{
		result = (result * 10) + t->format[t->i] - 48;
		t->i++;
	}
	return (result * sign);
}

void	perc_width_output(t_conv *t)
{
	if (t->conv_char == '%')
	{
		if (t->flag == 'x' && t->to_fill > 0)
		{
			t->fill_str = ft_strncat_mod(' ', t->to_fill, t->len);
			t->str = ft_strcat(t->fill_str, t->to_print, 0);
		}
		else if (t->flag == '-' && t->to_fill > 0)
			t->str = ft_realloc_mod(' ', t->to_print, t->width + 1, 0);
		else if (t->flag == '0' && t->to_fill > 0)
		{		
			t->fill_str = ft_strncat_mod('0', t->to_fill, t->len);
			t->str = ft_strcat(t->fill_str, t->to_print, 0);
		}
		else
			t->str = t->to_print;
		t->i++;
		t->plen = -1;
		t->free_switch = 1;
	}
}

