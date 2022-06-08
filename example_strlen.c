#include <stddef.h>

__attribute__((weak))
size_t  ft_strlen(char *str)
{
    const char *start = str;

    while (*str)
        str++;
    return (str - start);
}
