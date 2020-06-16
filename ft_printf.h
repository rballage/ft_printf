/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 15:30:26 by rballage          #+#    #+#             */
/*   Updated: 2020/06/12 16:21:21 by rballage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

# include "libft/libft.h"
# include "HEADERS/ft_macros.h"
# include "HEADERS/ft_types.h"

int		ft_printf(const char *format, ...);
#endif
