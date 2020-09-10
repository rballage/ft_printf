/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attributes_calculs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:42:22 by ydonse            #+#    #+#             */
/*   Updated: 2020/09/09 14:51:21 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_attributes_length(t_plist *list, int i)
{
	if (list->sharp)
		i += 2;
	if (list->plus == 1 || list->space == 1)
		i += 1;
	if (list->dot)
		i += ft_abs(list->precision);
	if (list->min_w > 0)
		i += list->min_w;
	return (i);
}

int		check_if_copy(t_plist *list, long double nb, int i, char *str)
{
	int size;

	size = ft_strlen(list->res);
	if (!(list->dot && !list->precision && !nb && list->type_entree == number))
	{
		if (list->type_entree == character && list->dot &&
			list->precision < size && list->string)
		{
			ft_strncpy(&str[i], list->res, list->precision);
			str[i + list->precision] = '\0';
			i += list->precision;
		}
		else
		{
			if (list->zero && nb < 0)
			{
				list->res++;
				size--;
			}
			if (list->type_entree == character && list->nb_size == 1
			&& !list->string)
				str[i] = list->type.c;
			else
				ft_strcpy(&str[i], list->res);
			i += (!size && list->type.c == '\0'
			&& list->type_entree == character  && list->nb_size == 1) ? 1 : size;
			str[i] = '\0';
		}
	}
	return (i);
}

int		check_normal_attributes(t_plist *list, long double nb, int i, char *str)
{
	if (list->dot && list->type_entree == number)
		list->zero = 0;
	i = check_sharp_hexa_minus(list, nb, 0, str);
	if (list->zero)
		i = check_plus(list, nb, i, str);
	i = check_field(list, nb, i, str);
	i = check_sharp_hexa_field(list, nb, i, str);
	if (!list->zero)
		i = check_plus(list, nb, i, str);
	i = pad_r_zero(list, nb, i, str);
	i = check_sharp_octal(list, nb, i, str);
	i = check_sharp_hexa(list, nb, i, str);
	i = check_if_copy(list, nb, i, str);
	i = check_field_minus(list, nb, i, str);
	i = pad_l_spaces(list, i, str);
	return (i);
}

int		check_float_attributes(t_plist *list, long double nb, int i, char *str)
{
	i = 0;
	if (list->zero)
		i = check_plus(list, nb, i, str);
	i = check_field(list, nb, i, str);
	if (!list->zero)
		i = check_plus(list, nb, i, str);
	i = check_if_copy(list, nb, i, str);
	i = check_field_minus(list, nb, i, str);
	return (i);
}

char	*add_attributes(t_plist *list, long double nb)
{
	char	*str;
	int		attribute_size;

	if (!nb && list->type.c == '\0' && !list->nb_size
	&& list->type_entree == character  && !list->string)
		list->nb_size = 1;
	else
		list->nb_size = ft_strlen(list->res);
	attribute_size = get_attributes_length(list, 0);
	str = ft_strnew(list->nb_size + attribute_size);
	if (list->f_type)
		check_float_attributes(list, nb, 0, str);
	else
		check_normal_attributes(list, nb, 0, str);
	return (str);
}
