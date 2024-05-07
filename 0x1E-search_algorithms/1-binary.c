#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array of integers using binary search
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: Value to search for
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index of the value in the array.
 */
int binary_search(int *array, size_t size, int value)
{
    size_t left = 0, right = size - 1, mid;

    /* Check if the array is NULL */
    if (array == NULL)
        return (-1);

    /* Binary search algorithm */
    while (left <= right)
    {
        mid = (left + right) / 2;

        /* Print the value being checked */
        printf("Value checked array[%ld] = [%d]\n", mid, array[mid]);

        /* If value is found at mid */
        if (array[mid] == value)
            return (mid);

        /* If value is greater, ignore left half */
        if (array[mid] < value)
            left = mid + 1;
        /* If value is smaller, ignore right half */
        else
            right = mid - 1;
    }

    /* Value not found, return -1 */
    return (-1);
}

