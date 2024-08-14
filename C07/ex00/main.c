#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
int     ft_strlen(char *str);
char    *ft_strcpy(char *dest, char *src);
char    *ft_strdup(char *src);

int main(void)
{
    // Test ft_strlen
    printf("Testing ft_strlen:\n");
    char *str1 = "Hello, World!";
    char *str2 = "";
    char *str3 = "A";
    printf("Length of '%s': %d (Expected: %lu)\n", str1, ft_strlen(str1), strlen(str1));
    printf("Length of '%s': %d (Expected: %lu)\n", str2, ft_strlen(str2), strlen(str2));
    printf("Length of '%s': %d (Expected: %lu)\n", str3, ft_strlen(str3), strlen(str3));
    printf("\n");

    // Test ft_strcpy
    printf("Testing ft_strcpy:\n");
    char dest1[20];
    char dest2[20];
    printf("Copied string: '%s' (Expected: '%s')\n", ft_strcpy(dest1, str1), str1);
    printf("Copied string: '%s' (Expected: '%s')\n", ft_strcpy(dest2, str2), str2);
    printf("\n");

    // Test ft_strdup
    printf("Testing ft_strdup:\n");
    char *dup1 = ft_strdup(str1);
    char *dup2 = ft_strdup(str2);
    char *dup3 = ft_strdup(str3);
    
    if (dup1) {
        printf("Duplicated string: '%s' (Expected: '%s')\n", dup1, str1);
        free(dup1);
    } else {
        printf("ft_strdup failed for '%s'\n", str1);
    }
    
    if (dup2) {
        printf("Duplicated string: '%s' (Expected: '%s')\n", dup2, str2);
        free(dup2);
    } else {
        printf("ft_strdup failed for '%s'\n", str2);
    }
    
    if (dup3) {
        printf("Duplicated string: '%s' (Expected: '%s')\n", dup3, str3);
        free(dup3);
    } else {
        printf("ft_strdup failed for '%s'\n", str3);
    }

    return 0;
}