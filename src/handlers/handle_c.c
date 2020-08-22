#include "ft_printf.h"

void	handle_c(t_plist *list, va_list *ap, int skip)
{
	list->type.c = (char)va_arg(*ap, int);
	if (!list->type.c)
	{
		list->res = ft_strnew(1);
	}
	else
		list->res = ft_strdup(&(list->type.c));
	list->type_entree = character;
	list->res = add_attributes(list, 0);
	list->skip += skip;
}
