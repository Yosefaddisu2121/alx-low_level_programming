#include "search_algos.h"
#define min(a, b) (((a) < (b)) ? (a) : (b))

/**
 * jump_search - Search for a value in a sorted array of integers using jump search
 * @array: A pointer to the first element of the array to search
 * @size: The number of elements in the array
 * @value: Value to search for
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index of the value in the array.
 */
int jump_search(int *array, size_t size, int value)
{
    size_t step = sqrt(size); /* Determine the step size*/
    size_t prev = 0; /* Previous step*/
    size_t curr; /* Current step*/

    /* Check if the array is NULL */
    if (array == NULL)
        return (-1);

    /* Jump search algorithm */
    while (array[min(step, size) - 1] < value)
    {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return (-1);
    }

    /* Linear search in the current block */
    curr = prev;
    while (array[curr] < value)
    {
        prev = curr;
        curr = min(curr + step, size);
        if (prev >= size)
            return (-1);
    }

    /* If the element is found */
    if (array[curr] == value)
        return (curr);

    /* Value not found, return -1 */
    return (-1);
}

