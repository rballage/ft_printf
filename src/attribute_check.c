/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:53:15 by ydonse            #+#    #+#             */
/*   Updated: 2020/09/10 19:08:13 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			chck_star(t_plist *list, const char *fmt, va_list *ap, t_bool field)
{
	if (*fmt == '*')
	{
		list->has_star = true;
		list->star_value = (int)va_arg(*ap, int);
		list->skip++;
		if (list->star_value < 0 && field)
		{
			list->minus = 1;
			list->star_value *= -1;
		}
		if (field)
			set_field(list, fmt, ap);
		return (1);
	}
	return (0);
}

void		check_attributes(t_plist *list, const char *format, va_list *ap)
{
	static const char	attributes[] = "0123456789-+.# *";
	static int	(*setters[])(t_plist*, const char *, __builtin_va_list*)
	= { &set_zero, &set_field, &set_field, &set_field, &set_field, &set_field,
		&set_field, &set_field, &set_field, &set_field, &set_minus, &set_plus,
		&set_precision, &set_sharp, &set_space};
	int					i;

	i = -1;
	format += chck_star(list, format, ap, true);
	while ((i = search_setters(*format, attributes)) > -1)
	{
		if (i != 15)
			format += (chck_star(list, format + 1, ap, i == 12 ? false : true)
			+ setters[i](list, format, ap));
		else
			format++;
	}
	check_cast_modifiers(list, format, ap);
}
