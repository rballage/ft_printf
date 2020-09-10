#include "ft_printf.h"

void	handle_x(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.ll = (long long)va_arg(*ap, unsigned int);
	list->mode = HEXA_LOW;
	list->res = convert_hexa(list->type.ll, list);
	save = list->res;
	list->res = add_attributes(list, list->type.ll);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
