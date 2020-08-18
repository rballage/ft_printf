/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:49:47 by ydonse            #+#    #+#             */
/*   Updated: 2020/08/18 08:57:26 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_plist	*new_list(void)
{
	t_plist *list;

	if (!(list = malloc(sizeof(t_plist))))
		exit(0);
	list->next = NULL;
	list->type_str = NULL;
	list->skip = 1;
	list->mode = 0;
	list->sharp = 0;
	list->minus = 0;
	list->plus = 0;
	list->zero = 0;
	list->space = 0;
	list->dot = 0;
	list->dot_size = 0;
	list->min_w = 0;
	list->string = 0;
	list->type_entree = number;
	list->nb_size = 0;
	list->percent = 0;
	list->sharp_placed = 0;
	list->f_type = 0;
	list->pointer = 0;
	list->uns = 0;
	return (list);
}

t_plist	*fill_list(const char *restrict format, va_list *ap, t_plist *list)
{
	t_plist		*origin;

	origin = list;
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			check_attribute_1(list, &(format[1]), ap);
			if (list->percent)
			{
				format++;
				while (*format && *format != '%')
					format++;
			}
			list->next = new_list();
			list = list->next;
		}
		format++;
	}
	return (origin);
}

void	free_list(t_plist *list)
{
	t_plist *current;

	while (list)
	{
		current = list;
		ft_strdel(&(list->type_str));
		list = list->next;
		free(current);
	}
}
