/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 14:47:59 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:46:00 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
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
	/*printf("t.i ---> %d\n", t.i);
	printf("format[i] ---> %cI\n", t.format[t.i]);
	printf("conv num ---> %d\n", t.conv_num);*/
	t.i--;
	/*if (t.format[t.i] != 0)
	{
		while (t.format[t.i] != 0)
		{
			write (1, &t.format[t.i++], 1);
			t.ret_val++;
		}
	}*/
	va_end(t.argp);
	return (t.ret_val);
}

void	printf_loop(t_conv *t)
{
	while (t->conv_num > 0 && t->format[t->i] != '\0')
	{
		t->free_switch = 0;
		get_conv(t);
		if (t->conv_char == '%')
			t->conv_num--;
		printf_parsing(t);
		ft_putstr(t->str);
		t->ret_val += ft_strlen(t->str);
		if (t->free_switch == 0)
			free (t->str);
		if (t->plen > 0)
			free(t->to_print);
				/*if (t->conv_num == 1)
			while (t->format[t->i] != 0)
			{
				write(1, &t->format[t->i++], 1);
				t->ret_val++;
			}*/
		t->conv_num--;
	}
}

int main(void)
{
	printf("%s%%\n", "oui");
	//printf("\nret val printf ---> %d\n", printf("%s", "oui"));
	ft_printf("%c%%", '3');
	//printf("\nret val ft_printf ---> %d\n", ft_printf("%5s", "oui"));
	return (0);
}
