#include "../include/ft_nm.h"

char *setTypesToPrint(char *options) {
    if (ft_strchr(options, 'u'))
        return ("Uw");
    else if (ft_strchr(options, 'g'))
        return ("UwWACBRDTnm");
    else if (ft_strchr(options, 'a'))
        return ("UWACBRDTNuwactrbdi");
    else
        return ("UWACBRDTurtwcbdi");
}

void    sortArray(size_t symbolCount, t_sym *symArray, char *options) {
    t_sym tmp;
    size_t i = 0;
    size_t j = 0;

    if (!ft_strchr(options, 'r')) {
        while (i < symbolCount - 1) {
            j = i + 1;
            while (j < symbolCount) {
                if (compareSymNames(symArray[i].name, symArray[j].name, symArray[i].ulValue, symArray[j].ulValue) > 0) {
                    tmp = symArray[i];
                    symArray[i] = symArray[j];
                    symArray[j] = tmp;
                }
                j++;
            }
            i++;
        }
    }
    else {
        while (i < symbolCount - 1) {
            j = i + 1;
            while (j < symbolCount) {
                if (compareSymNames(symArray[i].name, symArray[j].name, symArray[i].ulValue, symArray[j].ulValue) < 0) {
                    tmp = symArray[i];
                    symArray[i] = symArray[j];
                    symArray[j] = tmp;
                }
                j++;
            }
            i++;
        }
    }
}

void    printOutput(size_t symbolCount, t_sym *symArray, char *options) {
    char *toPrint = setTypesToPrint(options);
    for (size_t i = 0; i < symbolCount; i++) {
        if (!(symArray[i].name[0] == '\0' && symArray[i].type != 'a')
            && ft_strchr(toPrint, symArray[i].type)) {
            (symArray[i].type == 'U' || symArray[i].type == 'w' || symArray[i].type == 'W') ?
            write(1, "                ", 16) : write(1, symArray[i].hexValue, 16);
            write(1, " ", 1);
            write(1, &symArray[i].type, 1);
            write(1, " ", 1);
            write(1, symArray[i].name, ft_strlen(symArray[i].name));
            write(1, "\n", 1);
        }
    }
}

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

int compareSymNames(const char *first, const char *second, unsigned long firstValue, unsigned long secondValue) {
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
    if (*first == '\0' && *second != '\0')
        return -1;
    else if (*second == '\0' && *first != '\0')
        return 1;
    else if (firstValue < secondValue)
        return -1;
    return 1;
}