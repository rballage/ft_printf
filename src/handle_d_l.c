#include "ft_printf.h"

void	handle_ld(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.l = va_arg(*ap, long);
	list->res = ft_llitoa((long long)list->type.l);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.l);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
