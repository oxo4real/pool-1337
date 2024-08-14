#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	int size;
	int i;
	int *arr;

	size = end - start;
	if (size < 0)
		size *= -1;
	size += 1;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	if (end <= start)
	{
		while (end <= start)
		{
			arr[i] = end;
			end += 1;
			i++;
		}
	}
	else
	{
		while (end >= start)
		{
			arr[i] = end;
			end -= 1;
			i++;
		}
	}
	return (arr);
}

#include <stdio.h>

int main(void)
{
	int i;
	int *arr;

	i = 0;
	arr = ft_rrange(0, 5);
	while (i <= 5)
	{
		printf("%i\n", arr[i]);
		i++;
	}
}