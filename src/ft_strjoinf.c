#include "ft_printf.h"

char			*ft_strjoinf(char *s1, char *s2)
{
	char			*s1b;
	char			*s2b;
	char			*str;
	size_t			tot;

	str = NULL;
	if (!s1 && !s2)
		return (NULL);
	s1b = s1;
	s2b = s2;
	tot = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = ft_strnew(tot)))
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	free(s1b);
	free(s2b);
	return (str - tot);
}
char			*ft_strnjoinf(char *s1, int n1, char *s2, int n2)
{
	char			*str;
	size_t			tot;
	int i;

	i = -1;
	str = NULL;
	if (!(tot = n1 + n2))
		return (NULL);
	if (!(str = ft_strnew(tot)))
		return (NULL);
	while (++i < n1)
		str[i] = s1[i];
	i = -1;
	while (++i < n2)
		str[i + n1] = s2[i];
	// if (s1)
	// 	free(s1);
	// if (s2)
	// 	free(s1);
	str[tot] = '\0';
	return (str);
}
