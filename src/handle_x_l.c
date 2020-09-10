#include "ft_printf.h"

void	handle_lx(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.lu = va_arg(*ap, unsigned long);
	list->mode = HEXA_LOW;
	list->res = convert_hexa((unsigned long long)list->type.lu, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.lu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
