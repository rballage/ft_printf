#include "ft_printf.h"

void	handle_percent(t_plist *list, va_list *ap, int skip)
{
	list->type.c = '%';
	list->res = ft_strdup("%");
	list->type_entree = character;
	list->percent = 1;
	list->res = add_attributes(list, 0);
	list->skip += skip;
	(void)ap;
}
