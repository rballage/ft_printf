/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribute_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:53:15 by ydonse            #+#    #+#             */
/*   Updated: 2020/08/21 19:37:45 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_attributes(t_plist *list, const char *format, va_list *ap)
{
	static const char	attributes[] = "0123456789-+.# ";
	static void	(*setters[])(t_plist*, const char *) = { &set_zero,
		&set_field, &set_field, &set_field,
		&set_field, &set_field, &set_field, &set_field,
		&set_field, &set_field, &set_minus, &set_plus,
		&set_precision, &set_sharp, &set_space};
	int					i;

	i = 0;
	while ((i = search_setters(*format, attributes)) > -1)
	{
		setters[i](list, format);
		format += (i == 12) ? 1 : 0;
		if ((i > 0 && i < 10) || i == 12)
			while (*format >= '0' && *format <= '9')
				format++;
		else
			format++;
	}
	check_cast_modifiers(list, format, ap);
}
