/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ccroissa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/07 14:57:38 by ccroissa     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 19:39:57 by ccroissa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <inttypes.h>

typedef	struct	s_convert
{
	va_list		argp;
	char		char_to_print;
	char		flag;
	char		conv_char;
	char		*str;
	char		*to_print;
	char		*fill_str;
	void		*adress;
	int			to_convert;
	int			i;
	int			j;
	int			width;
	int			precision;
	int			len;
	int			to_fill;
	int			plen;
	int			ret_val;
	int			conv_num;
	uint8_t		free_switch;
	uint8_t		pswitch;
	uint8_t		neg;
	const char	*format;
}				t_conv;

void	conversion_u(t_conv *t);
void	conversion_c(t_conv *t);
void	conversion_p(t_conv *t);
void	conversion_perc(t_conv *t);
void	conversion_call(t_conv *it);
void	printf_loop(t_conv *t);
void	printf_parsing(t_conv *t);
void	printf_output(t_conv *t);
void	printf_width(t_conv *t);
void	printf_precision(t_conv *t);
void	get_conv(t_conv *t);
void	conv_number(t_conv *t);
int		ft_printf(const char *format,
		...) __attribute__((format(printf,1,2)));
int		atoi_struc(t_conv *t);
void	int_precision_output(t_conv *t);
void	int_width_output(t_conv *t);
void	string_precision_output(t_conv *t);
void	string_width_output(t_conv *t);
void	char_width_output(t_conv *t);
void	perc_width_output(t_conv *t);
#endif