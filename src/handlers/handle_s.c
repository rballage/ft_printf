#include "ft_printf.h"

void	handle_s(t_plist *list, va_list *ap, int skip)
{
	list->type.str = va_arg(*ap, char*);
	if (list->type.str)
		list->res = ft_strdup(list->type.str);
	else
	{
		list->res = ft_strdup("(null)");
		list->type.c = '.';
	}
	list->type_entree = character;
	list->string = 1;
	list->res = add_attributes(list, 0);
	list->skip += skip;
}
