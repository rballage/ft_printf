/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:15:36 by ydonse            #+#    #+#             */
/*   Updated: 2020/08/18 12:05:01 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assemble_str(t_plist *list, const char *restrict format, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (format[j])
	{
		if (format[j] == '%' && format[j + 1])
		{
			while (list->type_str[k])
				str[i++] = list->type_str[k++];
			if (list->type_entree == character && list->type.c == '\0' && !list->minus)
				str[i++] = '\0';
			k = 0;
			j += list->skip;
			list = list->next;
		}
		else if (format[j] == '%' && !format[j + 1])
			j++;
		else
			str[i++] = format[j++];
	}
	str[i] = '\0';
}

int		get_full_str_size(t_plist *list, const char *restrict format)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (format[j])
	{
		if (format[j] == '%' && format[j + 1])
		{
			if (list->type_entree == character && list->type.c == '\0')
			{
				i++;
				// printf("%s skip:%d\n", "0 detecté", list->skip);
			}
			else
				// printf("%s skip:%d\n", "0 non detecté", list->skip);

			i += ft_strlen(list->type_str);
			j += list->skip;
			list = list->next;
		}
		else if (format[j] == '%' && !format[j + 1])
			break ;
		else
		{
			i++;
			j++;
		}
	}
	return (i);
}

int		write_full_str(t_plist *list, const char *restrict format)
{
	int		i;
	char	*str;
	t_plist	*origin;
	int		size;

	size = 0;
	i = 0;
	origin = list;
	size = get_full_str_size(list, format);
	// if (!(str = malloc(sizeof(char) * (size + 1))))
	// 	exit(0);// s
	str = ft_strnew(size);
	list = origin;
	assemble_str(list, format, str);
	if (!list->nb_size && list->type_entree == character && list->type.c == '\0' && list->minus && list->min_w && !list->string)
	{
		str[0] = '\0';
		size--;
	}
	i = write(1, str, size);
	ft_strdel(&str);
	return (i);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_plist	*list;
	int		size;

	size = -1;
	list = new_list();
	va_start(ap, format);
	list = fill_list(format, &ap, list);
	size = write_full_str(list, format);
	va_end(ap);
	free_list(list);
	return (size);
}
