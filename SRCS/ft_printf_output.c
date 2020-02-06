/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_precision.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 14:06:12 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:31:40 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	int_precision_output(t_conv *t)
{
	if (ft_strchr("diuxX", t->conv_char))
	{
		if (t->neg == 0 && t->pswitch == 1 && t->plen >= 0)
		{
			t->fill_str = ft_strncat_mod('0', t->plen, t->len);
			t->str = ft_strcat(t->fill_str, t->to_print, 0);
		}
		else if (t->neg == 1 && t->pswitch == 1 && t->plen >= 0)
		{
			t->to_print = ft_substr(t->to_print, 1, t->len - 1, 1);
			t->fill_str = ft_strncat_mod('0', t->plen, t->len);
			t->str = ft_strcat(t->fill_str, t->to_print, 0);
			t->str = ft_strjoin("-", t->str, 1);
		}
		else
			t->str = t->to_print;
	}
}

void	int_width_output(t_conv *t)
{
	if (ft_strchr("diuxX", t->conv_char))
	{
		if (t->flag == '-' && t->width > t->len && t->pswitch == 1)
			t->str = ft_realloc_mod(' ', t->str, t->width + 1, 1);
		else if (t->flag == '-' && t->width > t->len && t->pswitch == 0)
			t->str = ft_realloc_mod(' ', t->str, t->width + 1, 0);
		else if (t->flag == '0' && t->to_fill > 0
			&& t->pswitch == 0 && t->neg == 1)
		{
			t->to_print = ft_substr(t->to_print, 1, t->len - 1, 1);
			t->fill_str = ft_strncat_mod('0', t->to_fill, t->len);
			t->str = ft_strcat(t->fill_str, t->to_print, 0);
			t->str = ft_strjoin("-", t->str, 1);
		}
		else if ((t->flag == '0' || t->flag == 'x') && t->width > t->len)
		{
			t->fill_str = (t->pswitch == 1 || 
				(t->flag == 'x' && t->pswitch == 0)) 
				? ft_strncat_mod(' ', t->to_fill, t->len)
				: ft_strncat_mod('0', t->to_fill, t->len);
			t->str = (t->pswitch == 1) ? ft_strcat(t->fill_str, t->str, 2)
				: ft_strcat(t->fill_str, t->str, 0);
		}
	}
}

void	string_precision_output(t_conv *t)
{
	if (t->conv_char == 's')
	{
		if (t->precision < t->len && t->pswitch == 1)
			t->str = ft_strtrim(t->to_print, &t->to_print[t->precision]);
		else
			t->str = t->to_print;
	}
}

void	string_width_output(t_conv *t)
{
	if (t->conv_char == 's')
	{
		if (t->flag == '-' && t->to_fill > 0)
			t->str = (t->pswitch == 1 && t->plen < 0) 
			? ft_realloc_mod(' ', t->str, t->width + 1, 1)
			: ft_realloc_mod(' ', t->to_print, t->width + 1, 0);
		else if (t->flag == 'x' && t->width == 0)
			t->free_switch = (t->pswitch == 1 && t->plen < 0) ? 0 : 1;
		else if (t->flag == 'x' && t->to_fill > 0)
		{
			t->fill_str = ft_strncat_mod(' ', t->to_fill, t->len);
			t->str = ft_strcat(t->fill_str, t->str, 1);
			t->free_switch = t->plen > 0 ? 0 : 1;
		}
	}
}

void	char_width_output(t_conv *t)
{
	if (ft_strchr("cp", t->conv_char))
	{
		if (t->char_to_print == 0)
		{
			t->to_fill--;
			t->ret_val++;
		}
		if (t->flag == 'x'  && t->width > 1)
		{
			t->fill_str = ft_strncat_mod(' ', t->to_fill, t->len);
			t->str = ft_strcat(t->fill_str, t->to_print, 2);
		}
		else if (t->flag == '-' && t->width > 1)
			t->str = ft_realloc_mod(' ', t->to_print, t->width + 1, 1);
		else
			free(t->to_print);
	}
}
