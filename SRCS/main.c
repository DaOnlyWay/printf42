/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 17:33:17 by ccroissa          #+#    #+#             */
/*   Updated: 2020/02/18 17:34:09 by ccroissa         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	//printf("%5u", 5);
	printf("\nret val printf ---> %d\n", printf("Bonjour .%6.3s. non *.%.5d. Oui *.%*%.5%*.*% HELL NO%%", "Bonsoir", 5, 010, 04, 10));
	//ft_printf("%-10%");
	ft_printf("\nret val ft_printf ---> %d\n", ft_printf("Bonjour .%6.3s. non *.%.5d. Oui *.%*%.5%*.*% HELL NO%%", "Bonsoir", 5, 010, 04, 10));
	return (0);
}
