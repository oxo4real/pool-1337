#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

void test_case(char *nbr, char *base_from, char *base_to, char *expected)
{
    char *result = ft_convert_base(nbr, base_from, base_to);
    printf("Input: nbr='%s', base_from='%s', base_to='%s'\n", nbr, base_from, base_to);
    printf("Expected: %s\n", expected);
    printf("Result  : %s\n", result);
    printf("Test %s\n\n", (result && strcmp(result, expected) == 0) ? "PASSED" : "FAILED");
    free(result);
}

int main()
{
    // Test case 1: Basic conversion
    test_case("42", "0123456789", "01", "101010");

    // Test case 2: Negative number
    test_case("-42", "0123456789", "0123456789abcdef", "-2a");

    // Test case 3: Zero
    test_case("0", "0123456789", "01", "0");

    // Test case 4: Binary to Hexadecimal
    test_case("1010", "01", "0123456789ABCDEF", "A");

    // Test case 5: Hexadecimal to Decimal
    test_case("FF", "0123456789ABCDEF", "0123456789", "255");

    // Test case 6: With whitespaces and signs
    test_case("  ++--+-42", "0123456789", "0123456789", "-42");

    // Test case 7: Invalid base_from
    test_case("42", "01234+56789", "0123456789", "NULL");

    // Test case 8: Invalid base_to
    test_case("42", "0123456789", "0123456789+", "NULL");

    // Test case 9: Empty string
    test_case("", "0123456789", "01", "0");

    // Test case 10: Large number (close to INT_MAX)
    test_case("2147483647", "0123456789", "01", "1111111111111111111111111111111");

    // Test case 11: Negative large number (close to INT_MIN)
    test_case("-2147483648", "0123456789", "0123456789abcdef", "-80000000");

    // Test case 12: Complex base
    test_case("Hello, World!", "!, abcdefghijklmnopqrstuvwxyz", "0123456789", "941946381");

    // Test case 13: Same base
    test_case("42", "0123456789", "0123456789", "42");

    return 0;
}
