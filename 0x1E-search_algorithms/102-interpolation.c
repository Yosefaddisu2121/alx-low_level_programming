#include "search_algos.h"

/**
 * interpolation_search - Search for a value in a sorted array of integers
 *                         using interpolation search
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: Value to search for
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index of the value in the array.
 */
int interpolation_search(int *array, size_t size, int value)
{
    size_t low = 0, high = size - 1;
    size_t pos;
    /* Check if the array is NULL */
    if (array == NULL)
        return (-1);

    /* Interpolation search algorithm */
    while (low <= high && value >= array[low] && value <= array[high])
    {
        if (low == high)
        {
            if (array[low] == value)
                return (low);
            return (-1);
        }

        /* Calculate the position using interpolation formula */
        pos = low + (((double)(high - low) /
                             (array[high] - array[low])) * (value - array[low]));

        /* If the value is found */
        if (array[pos] == value)
            return (pos);

        /* If the value is in the upper half */
        if (array[pos] < value)
            low = pos + 1;
        /* If the value is in the lower half */
        else
            high = pos - 1;
    }

    /* Value not found, return -1 */
    return (-1);
}

