#include "../include/ft_nm.h"

void    hexaUltoa(unsigned long value, char *dest) {
    int i = 0;
    unsigned long remainder = 0;

    while (value != 0) {
        remainder = value % 16;
        dest[i++] = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'a');
        value = value / 16;
    }
    if (i == 0)
        dest[i++] = '0';
    while (i < 16)
        dest[i++] = '0';
    dest[i] = '\0';
    int start = 0;
    int end = 15;
    char tmp = '0';
    while (start < end) {
        tmp = dest[start];
        dest[start] = dest[end];
        dest[end] = tmp;
        start++;
        end--;
    }
}

int compareSymNames(const char *first, const char *second) {
    while (*first && *second) {
        if (ft_isalnum(*first) && ft_isalnum(*second)) {
            int diff = ft_tolower(*first) - ft_tolower(*second);
            if (diff != 0) {
                return diff;
            }
            first++;
            second++;
        }
        else if (ft_isalnum(*first) && !ft_isalnum(*second))
            second++;
        else if (!ft_isalnum(*first) && ft_isalnum(*second))
            first++;
        else {
            first++;
            second++;
        }
    }
    if (*first == '\0')
        return -1;
    else if (*second == '\0')
        return 1;
    return (0);
}