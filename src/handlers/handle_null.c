#include "ft_printf.h"

void	handle_null(t_plist *list, const char *format, int ptr)
{
	list->type.c = *format;
	if (!list->type.c)
	{
		list->type.c = '.';
		list->res = ft_strnew(0);
	}
	else
	{
		list->res = ft_strdup(&(list->type.c));
	}
	list->type_entree = character;
	list->skip += ptr;
	if (list->res[0] == '\0')
		list->skip--;
	list->res = add_attributes(list, 0);
}
