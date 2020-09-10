#include "ft_printf.h"

void	handle_lld(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.ll = va_arg(*ap, long long);
	list->res = ft_llitoa(list->type.ll);
	save = list->res;
	list->res = add_attributes(list, (long double)list->type.ll);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
