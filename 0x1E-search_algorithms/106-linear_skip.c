#include <stdio.h>
#include <math.h>

/**
 * struct skiplist_s - Singly linked list with an express lane
 * @n: Integer stored in the node
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */
typedef struct skiplist_s
{
    int n;
    size_t index;
    struct skiplist_s *next;
    struct skiplist_s *express;
} skiplist_t;

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located,
 * or NULL if value is not present in list or if head is NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    if (list == NULL)
        return NULL;

    skiplist_t *express = list;
    while (express->express != NULL && express->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", express->express->index, express->express->n);
        if (express->express->n >= value)
            break;
        express = express->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           express->index, express->express ? express->express->index : 0);

    skiplist_t *current = express;
    while (current != NULL && current->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->next == NULL || current->next->n > value)
            return NULL;
        current = current->next;
    }

    printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

    if (current->n == value)
        return current;
    return NULL;
}

