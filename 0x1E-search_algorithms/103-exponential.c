#include <stddef.h> // Include for size_t
#include "search_algos.h" // Include for function declarations

/**
 * exponential_search - Search for a value in a sorted array of integers using exponential search
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: Value to search for
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index of the value in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    /* Check if the array is NULL */
    if (array == NULL)
        return (-1);

    /* Find the upper bound for the range */
    while (bound < size && array[bound] < value)
        bound *= 2;

    /* Perform binary search within the found range */
    return binary_search(array, min(bound, size), value);
}

/**
 * binary_search - Search for a value in a sorted array of integers using binary search
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: Value to search for
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index of the value in the array.
 */
int binary_search(int *array, size_t size, int value)
{
    size_t low = 0, high = size - 1, mid;

    /* Binary search algorithm */
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        /* If value is found at mid */
        if (array[mid] == value)
            return mid;
        /* If value is greater, ignore left half */
        else if (array[mid] < value)
            low = mid + 1;
        /* If value is smaller, ignore right half */
        else
            high = mid - 1;
    }

    /* Value not found, return -1 */
    return -1;
}

