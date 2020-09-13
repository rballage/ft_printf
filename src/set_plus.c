/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:09:07 by rballage          #+#    #+#             */
/*   Updated: 2020/09/13 18:09:08 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_plus(t_plist *list, const char *fmt, va_list *ap)
{
	list->plus = 1;
	list->skip++;
	(void)fmt;
	(void)ap;
	return (1);
}
