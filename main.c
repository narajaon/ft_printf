#include "ft_printf.h"
//#define VALUE "%ld, %ld, %ld, %ld", (long)INT_MAX + 1, LONG_MAX, INT_MAX, INT_MIN
#define VALUE "{%05.%}", 0

//"%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C", ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-','.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'

//"%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-','.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';','<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I','J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W','X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's','t', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}'


int		main(int ac, char **av)
{
	int		nb;
	int		ret;
	char	c;

	nb = 0;
	c = 'a';
	if (ac < 2)
		return (0);
	setlocale(LC_ALL, "");
//	ft_printf(av[1], c);
//	ft_printf(av[1], (long long int)ft_atoi(av[2]));
	ft_printf(VALUE);
//	ft_printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
//	printf("a%xb%xc%xd", 0, 55555, 100000);
	printf("\nvs\n");
//	ret = printf(av[1], ft_atoi(av[2]), ft_atoi(av[3]));
	ret = printf(VALUE);
	printf("\nreal out %d\n", ret);
	return (0);
}
