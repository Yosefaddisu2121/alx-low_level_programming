#include <stdio.h>
#include <stddef.h>

int recursive_binary_search(int *array, int value, int left, int right);

int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL)
        return -1;

    return recursive_binary_search(array, value, 0, size - 1);
}

int recursive_binary_search(int *array, int value, int left, int right)
{
    int i;
    if (left <= right)
    {
        int mid = (left + right) / 2;

        printf("Searching in array: ");
        for ( i = left; i <= right; i++)
        {
            printf("%d", array[i]);
            if (i < right)
                printf(", ");
        }
        printf("\n");

        if (array[mid] == value)
            return mid;
        else if (array[mid] < value)
            return recursive_binary_search(array, value, mid + 1, right);
        else
            return recursive_binary_search(array, value, left, mid - 1);
    }

    return -1;
}

