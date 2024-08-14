#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max);

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int *range;
    int size;
    int min, max;

    // Test case 1: Normal range
    min = 1;
    max = 5;
    size = ft_ultimate_range(&range, min, max);
    printf("Range from %d to %d: ", min, max);
    if (size > 0)
    {
        printf("Size: %d, Values: ", size);
        print_array(range, size);
        free(range);
    }
    else
        printf("ft_ultimate_range returned %d\n", size);

    // Test case 2: Negative numbers
    min = -3;
    max = 2;
    size = ft_ultimate_range(&range, min, max);
    printf("Range from %d to %d: ", min, max);
    if (size > 0)
    {
        printf("Size: %d, Values: ", size);
        print_array(range, size);
        free(range);
    }
    else
        printf("ft_ultimate_range returned %d\n", size);

    // Test case 3: Min equals Max
    min = 5;
    max = 5;
    size = ft_ultimate_range(&range, min, max);
    printf("Range from %d to %d: ", min, max);
    if (size > 0)
    {
        printf("Size: %d, Values: ", size);
        print_array(range, size);
        free(range);
    }
    else
        printf("ft_ultimate_range returned %d\n", size);

    // Test case 4: Min greater than Max
    min = 10;
    max = 5;
    size = ft_ultimate_range(&range, min, max);
    printf("Range from %d to %d: ", min, max);
    if (size > 0)
    {
        printf("Size: %d, Values: ", size);
        print_array(range, size);
        free(range);
    }
    else
        printf("ft_ultimate_range returned %d\n", size);

    return 0;
}