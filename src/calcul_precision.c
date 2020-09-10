/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:20:25 by ydonse            #+#    #+#             */
/*   Updated: 2020/08/24 16:35:19 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pad_r_zero(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = nb < 0 ? list->nb_size - 1 : list->nb_size;
	if (list->dot == 1 && list->precision > j && list->type_entree == number)
	{
		if (nb < 0)
		{
			str[i++] = '-';
			list->res++;
		}
		while (j < list->precision)
		{
			str[i++] = '0';
			j++;
		}
	}
	return (i);
}

int	pad_l_spaces(t_plist *list, int i, char *str)
{
	int j;

	j = list->nb_size;
	if (list->dot == 1 && list->precision < 0)
	{
		while (j < ft_abs(list->precision))
		{
			str[i++] = ' ';
			j++;
		}
	}
	return (i);
}
