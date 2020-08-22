typedef struct		s_rstring
{
	const size_t	size_origin;
	size_t			size_current;
	const char		*ptr_start_origin;
	const char		*ptr_end_origin;
	char			*ptr_start_current;
	char			*ptr_end_current;
}					t_rstring;

t_rstring			*new_rstring(size_t size)
{
	char			*str;
	t_rstring		*rstring;

	str = NULL;
	rstring = NULL;

	if (size)
	{
		if (!(rstring = (t_rstring*)malloc(sizeof(t_rstring))))
			return (NULL);
		if (!(str = (char*)malloc(sizeof(char) * size)))
			return (NULL);
		*(rstring->size_origin) = size;
		*(rstring->size_current) = size;
		*(rstring->ptr_start_origin) = str;
		*(rstring->ptr_start_current) = str;
		*(rstring->ptr_end_origin) = &str[size - 1];
		*(rstring->ptr_end_current) = &str[size - 1];
		ft_bzero(rstring->ptr_start_origin, size);
		return (&rstring);
	}
	return (NULL);
}
