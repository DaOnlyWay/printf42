/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:35:51 by ccroissa          #+#    #+#             */
/*   Updated: 2021/01/25 14:00:44 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	conversion_xup(t_conv *t)
{
	if (t->to_conv == 0)
	{
		if (!(t->to_print = ft_calloc(2, sizeof(char))))
			return ;
		t->to_print[0] = '0';
	}
	else
		t->to_print = uitoa_base((unsigned int)t->to_conv, "0123456789ABCDEF");
}

void	conversion_x(t_conv *t)
{
	if (t->to_conv == 0)
	{
		if (!(t->to_print = ft_calloc(2, sizeof(char))))
			return ;
		t->to_print[0] = '0';
	}
	else
		t->to_print = uitoa_base((unsigned int)t->to_conv, "0123456789abcdef");
}

void	conversion_d(t_conv *t)
{
	t->to_print = ft_itoa(t->to_conv);
}
