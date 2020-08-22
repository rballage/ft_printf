/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other_modifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:20:31 by ydonse            #+#    #+#             */
/*   Updated: 2020/08/21 19:48:19 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_ll_type(t_plist *list, const char *format, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_ll[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_lld, handle_lld, handle_llu, handle_llo, handle_llx,
		handle_llx_maj, handle_llu};

	i = 0;
	if ((i = search_setters(format + 1, "diuoxXU")) != -1)
		function_ll[i](list, ap, skip);
	else if (search_setters(format + 1, "hlLjz") != -1)
	{
		while (search_setters(format + 1, "hlLjz") != -1)
		{
			format++;
			skip++;
		}
		if ((i = search_setters(format + 1, "diuoxXU")) != -1)
			function_ll[i](list, ap, skip);
		else
			handle_null(list, format + 1, skip);
	}
	else
		handle_null(list, format + 1, skip);
}

void	check_hh_type(t_plist *list, const char *format, va_list *ap, int skip)
{
	int			i;
	static void (*function_hh[])(struct s_plist*, __builtin_va_list*,
		int) = { handle_hhd, handle_hhd, handle_hhu, handle_hho,
		handle_hhx, handle_hhx_maj};

	i = 0;
	if ((i = search_setters(format + 1, "diuoxXU")) != -1)
		function_hh[i](list, ap, skip);
	else if (search_setters(format + 1, "hlLjz") != -1)
	{
		while (search_setters(format + 1, "hlLjz") != -1)
		{
			format++;
			skip++;
		}
		if ((i = search_setters(format + 1, "diuoxXU")) != -1)
			function_hh[i](list, ap, skip);
		else
			handle_null(list, format + 1, skip);
	}
	else
		handle_null(list, format + 1, skip);
}

void	check_l_maj_type(t_plist *list, const char *format,
	va_list *ap, int skip)
{
	if (format + 1 == 'f')
		handle_lf_maj(list, ap, skip);
	else if (search_setters(format + 1, "hlLjz") != -1)
	{
		while (search_setters(format + 1, "hlLjz") != -1)
		{
			format++;
			skip++;
		}
		if (format + 1 == 'f')
			handle_lf_maj(list, ap, skip);
		else
			handle_null(list, format + 1, skip);
	}
	else
		handle_null(list, format + 1, 2);
}
