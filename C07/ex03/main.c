#include <stdio.h>
#include <stdlib.h>

// Include your function prototypes here
char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
    char *result;

    // Test case 1: Normal case
    char *strs1[] = {"Hello", "world", "of", "programming"};
    result = ft_strjoin(4, strs1, " ");
    printf("Test 1: %s\n", result);
    free(result);

    // Test case 2: Empty separator
    char *strs2[] = {"One", "Two", "Three"};
    result = ft_strjoin(3, strs2, "");
    printf("Test 2: %s\n", result);
    free(result);

    // Test case 3: Single string
    char *strs3[] = {"Lone wolf"};
    result = ft_strjoin(1, strs3, ", ");
    printf("Test 3: %s\n", result);
    free(result);

    // Test case 4: Empty strings
    char *strs4[] = {"", "", ""};
    result = ft_strjoin(3, strs4, "---");
    printf("Test 4: %s\n", result);
    free(result);

    // Test case 5: Size 0
    result = ft_strjoin(0, NULL, "");
    printf("Test 5: '%s'\n", result);
    free(result);

    return 0;
}