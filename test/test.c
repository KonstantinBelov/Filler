#include "filler.h"

char	*ft_strstr_(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	print_matrix_test(char **matrix, int n, int x)
{
	int		y;
	int		i;

	y = -1;
	while (++y < n)
	{
		i = -1;
		while (++i < x)
			write(2, &matrix[y][i], 1);
		write (2, "\n", 1);
	}
}

void	print_matrix_test_int(int **matrix, int n, int x)
{
	int		y;
	int		i;

	y = -1;
	while (++y < n)
	{
		i = -1;
		while (++i < x)
            fprintf(stderr, " %2d ", matrix[y][i]);
		write (2, "\n", 1);
	}
}