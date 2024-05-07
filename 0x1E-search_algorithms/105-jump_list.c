#include <stdio.h>
#include <math.h>
/**
 * jump_list - searches for a value in a sorted list of integers
 * using the Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located,
 * or NULL if value is not present in list or if list is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    if (list == NULL)
        return NULL;

    size_t jump = sqrt(size);
    listint_t *current = list;
    listint_t *prev = NULL;

    while (current->next != NULL && current->n < value)
    {
        prev = current;
        for (size_t i = 0; i < jump && current->next != NULL; i++)
            current = current->next;

        printf("Value checked at index [%lu] = [%d]\n", current->n, current->n);

        if (current->n >= value || current->next == NULL)
            break;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->n, current->n);

    while (prev->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", prev->n, prev->n);
        if (prev->next == NULL || prev->next->n > value)
            return NULL;
        prev = prev->next;
    }

    printf("Value checked at index [%lu] = [%d]\n", prev->n, prev->n);

    if (prev->n == value)
        return prev;
    return NULL;
}

