#include "ft_printf.h"

void	handle_hhd(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	if (list->undef_behavior)
	{
		list->type.ll = (long long)va_arg(*ap, int);
		list->res = ft_llitoa((long long)list->type.ll);
		save = list->res;
		list->res = add_attributes(list, (long double)list->type.ll);
	}
	else
	{
		list->type.c = (char)va_arg(*ap, int);
		list->res = ft_itoa((int)list->type.c);
		save = list->res;
		list->res = add_attributes(list, (long double)list->type.c);
	}
	list->skip += skip;
	if (save != list->res)
		free(save);
}
