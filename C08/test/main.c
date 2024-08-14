#include <stdio.h>
#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

int main(void)
{
    // Test case 1: Normal usage
    char *strs1[] = {"Hello", "World", "42", "School"};
    int size1 = 4;
    struct s_stock_str *tab1 = ft_strs_to_tab(size1, strs1);
    
    printf("Test case 1:\n");
    ft_show_tab(tab1);
    printf("\n");

    // Test case 2: Empty string
    char *strs2[] = {"", "Test", ""};
    int size2 = 3;
    struct s_stock_str *tab2 = ft_strs_to_tab(size2, strs2);
    
    printf("Test case 2:\n");
    ft_show_tab(tab2);
    printf("\n");

    // Test case 3: Single string
    char *strs3[] = {"SingleString"};
    int size3 = 1;
    struct s_stock_str *tab3 = ft_strs_to_tab(size3, strs3);
    
    printf("Test case 3:\n");
    ft_show_tab(tab3);
    printf("\n");

    // Test case 4: Zero size
    char **strs4 = NULL;
    int size4 = 0;
    struct s_stock_str *tab4 = ft_strs_to_tab(size4, strs4);
    
    printf("Test case 4:\n");
    ft_show_tab(tab4);
    printf("\n");

    // Free allocated memory
    // Note: In a real program, you should implement a function to free the memory properly
    // This is just a simple cleanup for the test cases
    for (int i = 0; i < size1; i++)
        free(tab1[i].copy);
    free(tab1);

    for (int i = 0; i < size2; i++)
        free(tab2[i].copy);
    free(tab2);

    for (int i = 0; i < size3; i++)
        free(tab3[i].copy);
    free(tab3);

    free(tab4);

    return 0;
}
