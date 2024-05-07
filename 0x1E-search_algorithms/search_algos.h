#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

/**
 * struck lists_s - singly linked list
 *
 * @n : Integer
 *  @Index: Index of the node in the list
 *  @next: Pointer to the next node
 */
typedef struct listint_s
{
	    int n;
	    size_t index;
	    struct lisint_s *next;
}listint_t;

/**
 *  struct skiplist_s - singly linked list with an express lane
 *
 *  @n : integer
 *  @index: Index of the node in the list
 *  @next: Pointer ti the next node
 *  @express: Pointer to the next node in the express lane
 *
 */
typedef struct skiplist_s
{
	    int n;
	    size_t index;
	    struct skiplist_s *next;
	    struct skiplist_s *express;
}skiplist_t;
int linear_search(int *array,size_t size,int value);
int binary_search(int *array,size_t size,int value);
int jump_search(int *array,size_t size,int value);
int interpolation_search(int *array,size_t size,int value);
int exponential_search(int *array,size_t size,int value);
int advanced_binary(int *array,size_t size,int value);
listint_t *jump_list(listint_t *list,size_t size,int value);
skiplist_t *linear_skip(skiplist_t *list,int value);

#endif /* SEARCH_ALGOS_H */
