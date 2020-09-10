/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cast_modifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydonse <ydonse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 11:20:31 by ydonse            #+#    #+#             */
/*   Updated: 2020/09/10 20:07:58 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		check_l_type(t_plist *list, const char *format, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_l[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_ld, handle_ld, handle_lu, handle_lo, handle_lx,
			handle_lx_maj, handle_lf, handle_llu};

	if ((i = search_setters(*(format + 1), "diuoxXfU")) != -1)
		function_l[i](list, ap, skip);
	else if (*(format + 1) == 'l')
		check_ll_type(list, format + 1, ap, skip + 1);
	else if (search_setters(*(format + 1), "hLjz#") != -1)
	{
		while (search_setters(*(format + 1), "hLjz#") != -1)
		{
			if (*(format + 1) == '#')
				list->sharp = 1;
			format++;
			skip++;
		}
		if ((i = search_setters(*(format + 1), "diuoxXfU")) != -1)
			function_l[i](list, ap, skip);
		else
			handle_null(list, format + 1, skip);
	}
	else
		handle_null(list, format + 1, skip);
}

static void		check_h_type(t_plist *list, const char *format, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_h[])(struct s_plist*, __builtin_va_list*,
		int) = { handle_hd, handle_hd, handle_hu, handle_ho,
		handle_hx, handle_hx_maj, handle_lu};

	if (*(format + 1) == 'h')
		check_hh_type(list, format + 1, ap, skip + 1);
	else if (search_setters(*(format + 1), "lLjz#") != -1)
	{
		while (search_setters(*(format + 1), "lLjz#") != -1)
		{
			if (*(format + 1) == '#')
				list->sharp = 1;
			format++;
			skip++;
		}
		if ((i = search_setters(*(format + 1), "diuoxXU")) != -1)
			function_h[i](list, ap, skip);
		else
			handle_null(list, format + 1, skip);
	}
	else if ((i = search_setters(*(format + 1), "diuoxXU")) != -1)
		function_h[i](list, ap, skip);
	else
		handle_null(list, format + 1, skip);
}

static void		check_j_type(t_plist *list, const char *format, va_list *ap,
	int skip)
{
	int			i;
	static void (*function_j[])(struct s_plist*, __builtin_va_list*,
		int) = { handle_lld, handle_llu, handle_llx, handle_llx_maj,
			handle_lld, handle_llo, handle_llu};

	i = 0;
	if ((i = search_setters(*(format + 1), "duxXioU")) != -1)
		function_j[i](list, ap, skip);
	else if (search_setters(*(format + 1), "hlLjz#") != -1)
	{
		while (search_setters(*(format + 1), "hlLjz#") != -1)
		{
			if (*(format + 1) == '#')
				list->sharp = 1;
			format++;
			skip++;
		}
		if ((i = search_setters(*(format + 1), "diuoxXU")) != -1)
			function_j[i](list, ap, skip);
		else
			handle_null(list, format + 1, skip);
	}
	else
		handle_null(list, format + 1, skip);
}

static void		check_x_type(t_plist *list, const char *format, va_list *ap)
{
	static void (*function_x[]) (struct s_plist*, __builtin_va_list*,
		int) = {handle_d, handle_s, handle_p, handle_u, handle_c, handle_x,
		handle_x_maj, handle_f, handle_d, handle_o, handle_lu, handle_percent};
	int			i;

	i = 0;
	if ((i = search_setters(*format, "dspucxXfioU%")) != -1)
		function_x[i](list, ap, 1);
	else
		handle_null(list, format, 1);
}

void			check_cast_modifiers(t_plist *list, const char *format, va_list *ap)
{
	if (*format == 'l' || *format == 'z')
		check_l_type(list, format, ap, 2);
	else if (*format == 'h')
		check_h_type(list, format, ap, 2);
	else if (*format == 'j')
		check_j_type(list, format, ap, 2);
	else if (*format == 'L')
		check_l_maj_type(list, format, ap, 2);
	else
		check_x_type(list, format, ap);
}
