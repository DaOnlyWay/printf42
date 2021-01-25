/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:05:33 by ccroissa          #+#    #+#             */
/*   Updated: 2021/01/25 16:32:03 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	strc_init(t_conv *t)
{
	t->to_print = NULL;
	t->str = NULL;
	t->flag = 'x';
	t->width = 0;
	t->prec = -1;
	t->neg = 0;
	t->to_conv = 0;
	t->pswitch = 0;
	t->plen = 0;
	t->to_fill = 0;
	t->adress = NULL;
	t->char_to_print = 0;
	t->to_conv = 0;
	t->free_switch = 0;
	t->c_zero = 0;
	t->err = 0;
}

void	end_frees(t_conv *t)
{
	if (ft_strchr("sp", t->conv_char)
		&& t->flag == 'x' && t->to_fill > 0 && t->adress == NULL)
		free(t->fill_str);
	if (t->free_switch == 0)
		free(t->str);
	if ((((t->plen > 0) && ft_strchr("diuxXc", t->conv_char))
		|| ((t->plen <= 0) && ft_strchr("xX", t->conv_char))
		|| ((t->width > 0) && ft_strchr("di", t->conv_char)
		&& t->flag == '-')) && t->err == 0 && (t->err = 1))
		free(t->to_print);
}
