#include "ft_printf.h"

void	handle_llx_maj(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.llu = (unsigned long long)va_arg(*ap, long long);
	list->mode = HEXA_HIGH;
	list->res = convert_hexa(list->type.llu, list);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.llu);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
