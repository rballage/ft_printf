/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_neg_min_field.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:42:51 by rballage          #+#    #+#             */
/*   Updated: 2020/09/04 14:46:25 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_char_field_minus(t_plist *list, int i, int j, char *str)
{
	char c;

	c = ' ';
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
		if ((list->type_entree == character  && list->nb_size == 1
		&& list->type.c != '\0') || list->string)
			j++;
		while (j++ <= list->min_w - list->nb_size)
			str[i++] = c;
	}
	// str[i] = '\0';
	list->reslen = i;
	return (i);
}

int	fill_nb_field_minus(t_plist *list, int i, int j, char *str)
{
	if (!(list->precision > list->nb_size) && list->nb_size == 1 && list->res[0] == '0'
	&& (!list->precision && list->dot))
		list->nb_size = 0;
	if (list->precision > list->nb_size)
		while (j++ < list->min_w - list->precision)
			str[i++] = ' ';
	else
		while (j++ < list->min_w - list->nb_size)
			str[i++] = ' ';
	str[i] = '\0';
	return (i);
}

int	check_nb_field_minus(t_plist *list, long double nb, int i, char *str)
{
	int j;

	j = 0;
	if (!list->pointer && list->sharp == 1 && list->mode != OCTAL && list->mode && nb != 0)
		j += 2;
	if (list->sharp == 1 && list->mode == OCTAL && list->mode && nb != 0
		&& !(list->dot && list->precision > list->nb_size))
		j++;
	if (list->pointer)
		j += 2;
	if ((list->plus == 1 || list->space) && nb >= 0 && list->mode == 0)
		j++;
	if (list->dot && nb < 0 && list->min_w > list->precision
		&& list->precision > list->nb_size - 1)
		j++;
	i = fill_nb_field_minus(list, i, j, str);
	return (i);
}

int	check_char_field_minus(t_plist *list, int i, char *str)
{
	int j;

	j = 0;
	if (list->type.c == '\0')
		j++;
	if (list->dot && list->precision == 0 && !list->string)
		j++;
	i = fill_char_field_minus(list, i, j, str);
	return (i);
}

int	check_field_minus(t_plist *list, long double nb, int i, char *str)
{
	if (list->min_w > list->nb_size && list->min_w > list->precision
	&& list->minus && list->type_entree == number)
		i = check_nb_field_minus(list, nb, i, str);
	if (list->type_entree == character && list->minus)
		i = check_char_field_minus(list, i, str);
	return (i);
}
