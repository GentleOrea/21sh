#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void	*dst;

	if (!ptr)
		return (malloc(size));
	if (!(dst = malloc(size)))
		return (0);
	ft_memcpy(dst, ptr, old > size ? size : old);
	while (old < size)
		((char*)dst)[old++] = 0;
	return (dst);
}
