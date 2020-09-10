#include "ft_printf.h"

void	handle_ho(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.us = (unsigned short)va_arg(*ap, unsigned int);
	list->mode = OCTAL;
	list->res = convert_octal((unsigned int)list->type.us);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.us);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
