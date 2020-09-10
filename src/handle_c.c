#include "ft_printf.h"

void	handle_c(t_plist *list, va_list *ap, int skip)
{
	char *save;

	save = NULL;
	list->type.c = (char)va_arg(*ap, int);
	list->res = ft_strnew(1);
	save = list->res;
	list->res[0] = list->type.c;
	list->type_entree = character;
	list->res = add_attributes(list, 0);
	list->skip += skip;
	if (save != list->res)
		free(save);
}
