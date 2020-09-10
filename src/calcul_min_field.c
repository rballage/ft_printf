/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_min_field.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:28:08 by ydonse            #+#    #+#             */
/*   Updated: 2020/09/09 15:10:49 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_char_field(t_plist *list, int i, int j, char *str)
{
	char c;

	c = list->zero ? '0' : ' ';
	if (list->dot)
	{
		if (list->precision >= list->nb_size)
			while (j++ < list->min_w - list->nb_size)
				str[i++] = c;
		if (list->string || (!list->string && list->precision >= 0))
			while (j++ < list->min_w - list->precision)
				str[i++] = c;
	}
	else if (!list->dot)
	{
		if (list->type_entree == character  && list->type.c == '\0')
				j--;
		while (j++ < list->min_w - list->nb_size)
			str[i++] = c;
	}
	list->reslen = (list->type_entree == character
	&& list->type.c == '\0') ? i + 1 : i;
	return (i);
}

int	fill_nb_field(t_plist *list, int i, int j, char *str)
{
	char c;

	c = list->zero ? '0' : ' ';
	if (list->precision > list->nb_size)
		while (j++ < list->min_w - list->precision)
			str[i++] = c;
	else
		while (j++ < list->min_w - list->nb_size)
			str[i++] = c;
	return (i);
}

int	check_char_field(t_plist *list, int i, char *str)
{
	int j;

	j = 0;
	if (list->type.c == '\0' && !(list->dot && !list->precision))
		j++;
	if (list->dot && list->precision == 0 && !list->string)
		j++;
	i = fill_char_field(list, i, j, str);
	return (i);
}

int	check_nb_field(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = 0;
	if (list->sharp == 1 && list->mode != OCTAL && list->mode != 0
		&& nb != 0 && !list->pointer)
		j += 2;
	if (list->sharp && list->mode == OCTAL && nb != 0 &&
		!(list->dot && list->precision > list->nb_size))
		j++;
	if (list->pointer)
		j += 2;
	if (list->dot && nb < 0 && list->min_w > list->precision
		&& list->precision > list->nb_size - 1)
		j++;
	if ((list->plus || list->space) && nb >= 0 && list->mode == 0)
		j++;
	if (list->dot && list->min_w > list->precision && !list->precision && !nb)
		j--;
	i = fill_nb_field(list, i, j, str);
	return (i);
}

int	check_field(t_plist *list, long double nb, int i, char *str)
{
	if (list->zero && nb < 0)
		str[i++] = '-';
	if (list->min_w > list->nb_size && list->min_w > list->precision
		&& !list->minus && list->precision >= 0 && list->type_entree == number)
		i = check_nb_field(list, nb, i, str);
	if (list->type_entree == character && !list->minus)
		i = check_char_field(list, i, str);
	return (i);
}
