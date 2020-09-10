
#include "libft/includes/libft.h"
#include "includes/ft_printf.h"
#include <stdio.h>
// // #include <stdlib.h>
// // #include <locale.h>
// // #include <wchar.h>
#include <limits.h>
#include <float.h>

int		main(void)
{
// ft_printf("%10s is a string", "");
// printf("%10s is a string\n", "s");
// ft_printf("%10s is a string\n", "s");
// ft_printf("%-5.0d\n", 0);

// ft_printf("%#");
// printf("%23s\n", "hello");
printf("%0**s\n", 4, -4, "ABC");
// ft_printf("%lld\n", (long long)-10);
// printf("%l*d\n", -1, 0);
// printf("%-5.0d\n", 0);
// ft_printf("ft|%ll#x\n", 9223372036854775807);
// ft_printf("ft|%l#x\n", 9223372036854775807);
// ft_printf("ft|%h#x\n", 9223372036854775807);

// printf("pr|%ll#x\n", 9223372036854775807);

// ft_printf("%5.2s is a string\n", "");
// ft_printf("%2c", 'a');
// ft_printf("%5.6s is a string\n", "d");
// ft_printf("%s is a string\n", "d");
	// ft_printf("01ftB%3c\n", 'b'); // duplication
	// ft_printf("02ftB%3c\n", 0); // ajouter neg min field logic à min field ? ou ajout 0 apres minfield value
	// ft_printf("03ftB%15c\n", 'b');
	// ft_printf("04ftB%c\n", 'b');
	// ft_printf("05ftS%-45s\n", "bouh");
	// ft_printf("06ftS%-45s\n", 0);
	// ft_printf("07ftS%15s\n", "bouh");
	// ft_printf("08ftS%15s\n", 0);
	// ft_printf("09ftS%s\n", "bouh");
	// ft_printf("10ftS%s\n", 0);
	//
	// printf("\n01prB%3c\n", 'b'); // duplication
	// printf("02prB%3c\n", 0); // ajouter neg min field logic à min field ? ou ajout 0 apres minfield value
	// printf("03prB%15c\n", 'b');
	// printf("04prB%c\n", 'b');
	// printf("05prS%-45s\n", "bouh"); // space en trop
	// printf("06prS%-45s\n", NULL);
	// printf("07prS%15s\n", "bouh");
	// printf("08prS%15s\n", NULL);
	// printf("09prS%s\n", "bouh");
	// printf("10prS%s\n", NULL);

	// printf("pr0%-15c\n", 0);
	// ft_printf("ft0%-15c\n", 0);
	// printf("prB%-15c\n", 'b');
	// ft_printf("1ft=%-15c\n", 0);
	// printf("1nn=%-15c\n", 0);
	// ft_printf("2ft=%15c\n", 0);
	// printf("2nn=%15c\n", 0);
	// ft_printf("3ft=%-15c\n", 'd');
	// printf("3nn=%-15c\n", 'd');
	// ft_printf("4ft=%15c\n", 'd');
	// printf("4nn=%15c\n", 'd');
	// ft_printf("%-15c\n", 0);

	// printf("%15c\n", 'd');

	// printf("%s\n", ft_strnjoinf("\0", 2, "123", 3));
	// printf("%c\n", '\0');

	return (0);
}
