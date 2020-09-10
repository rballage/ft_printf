#include "ft_printf.h"

void	handle_p(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->sharp = 1;
	list->pointer = 1;
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_LOW;
	list->res = convert_hexa(list->type.lu, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
