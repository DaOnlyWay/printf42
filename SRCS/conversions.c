/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   conversions.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 16:54:05 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:44:38 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	conversion_u(t_conv *t)
{
	unsigned int	temp;

	temp = t->to_convert;
	t->to_print = uitoa(temp);
}

void	conversion_c(t_conv *t)
{
	t->to_print = NULL;
	if (t->width > 0)
	{
		if (!(t->to_print = ft_calloc(t->width + 1, sizeof(char))))
			return;
		t->to_print[0] = t->char_to_print;
	}
	else
	{
		t->str = NULL;
		if(!(t->str = ft_calloc(2, sizeof(char))) || 
		!(t->to_print = ft_calloc(2, sizeof(char))))
			return;
		t->to_print[0] = t->char_to_print;
		t->str[0] = t->char_to_print;;
	}
}

void	conversion_p(t_conv *t)
{
	unsigned long num;

	num = (unsigned long)t->adress;
	t->to_print = uitoa_base(num, "0123456789abcdef");
	t->to_print = ft_strjoin("0x10", t->to_print, 1);
}

void	conversion_perc(t_conv *t)
{
	t->to_print = NULL;
	if(!(t->to_print = ft_calloc(2, sizeof(char))))
		return;
	t->to_print[0] = '%';
	printf("to print in conv ---> %s\n", t->to_print);
}
