#include "ft_printf.h"

void	handle_llu(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.ll = va_arg(*ap, long long);
	list->res = ft_lutoa(list->type.ll);
	save = list->res;
	list->uns = 1;
	list->res = add_attributes(list, (long double)list->type.ll);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
