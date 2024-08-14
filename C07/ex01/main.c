#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max);

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
    int *result;
    int min, max;

    // Test case 1: Normal range
    min = 1;
    max = 5;
    result = ft_range(min, max);
    if (result)
    {
        printf("Range from %d to %d: ", min, max);
        print_array(result, max - min);
        free(result);
    }
    else
        printf("ft_range returned NULL for min=%d, max=%d\n", min, max);

    // Test case 2: Negative numbers
    min = -3;
    max = 2;
    result = ft_range(min, max);
    if (result)
    {
        printf("Range from %d to %d: ", min, max);
        print_array(result, max - min);
        free(result);
    }
    else
        printf("ft_range returned NULL for min=%d, max=%d\n", min, max);

    // Test case 3: Min equals Max
    min = 5;
    max = 5;
    result = ft_range(min, max);
    if (result)
    {
        printf("Range from %d to %d: ", min, max);
        print_array(result, max - min);
        free(result);
    }
    else
        printf("ft_range returned NULL for min=%d, max=%d\n", min, max);

    // Test case 4: Min greater than Max
    min = 10;
    max = 5;
    result = ft_range(min, max);
    if (result)
    {
        printf("Range from %d to %d: ", min, max);
        print_array(result, max - min);
        free(result);
    }
    else
        printf("ft_range returned NULL for min=%d, max=%d\n", min, max);

    return 0;
}