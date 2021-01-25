/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:24:46 by ccroissa          #+#    #+#             */
/*   Updated: 2021/01/25 16:30:37 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdlib.h>
# include <inttypes.h>

typedef	struct			s_convert
{
	va_list				argp;
	unsigned char		char_to_print;
	char				flag;
	char				conv_char;
	char				*str;
	char				*to_print;
	char				*fill_str;
	void				*adress;
	int					to_conv;
	int					i;
	int					j;
	int					width;
	int					prec;
	int					len;
	int					to_fill;
	int					plen;
	int					ret_val;
	int					conv_num;
	int					err;
	uint8_t				mswitch;
	uint8_t				zswitch;
	uint8_t				free_switch;
	uint8_t				pswitch;
	uint8_t				neg;
	uint8_t				c_zero;
	const char			*format;
}						t_conv;

int						ft_printf(const char *format,
						...) __attribute__((format(printf,1,2)));
int						atoi_struc(t_conv *t);
void					strc_init(t_conv *t);
void					conversion_u(t_conv *t);
void					conversion_d(t_conv *t);
void					conversion_xup(t_conv *t);
void					conversion_x(t_conv *t);
void					conversion_c(t_conv *t);
void					conversion_p(t_conv *t);
void					conversion_perc(t_conv *t);
void					conversion_call(t_conv *t);
void					empty_string(t_conv *t);
void					end_frees(t_conv *t);
void					str_mflag_zprec(t_conv *t);
void					get_string(t_conv *t);
void					nul_char_conv(t_conv *t);
void					nul_char_output(t_conv *t);
void					printf_loop(t_conv *t);
void					printf_parsing(t_conv *t);
void					printf_output(t_conv *t);
void					printf_width(t_conv *t);
void					width_arg(t_conv *t);
void					printf_precision(t_conv *t);
void					get_conv(t_conv *t);
void					conv_number(t_conv *t);
void					int_precision_output(t_conv *t);
void					int_width_output(t_conv *t);
void					string_precision_output(t_conv *t);
void					string_width_output(t_conv *t);
void					address_width_output(t_conv *t);
void					char_width_output(t_conv *t);
void					perc_width_output(t_conv *t);
void					text_print(t_conv *t);
#endif
