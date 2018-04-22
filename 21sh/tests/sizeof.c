#include <stdio.h>

int	main()
{
	int	val[6];
	printf("%lu\n%lu\n", sizeof(val), sizeof(int[6]));
	printf("%lu\n", sizeof(int));
	return (0);
}
