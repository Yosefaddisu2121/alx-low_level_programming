#include "search_algos.h"

/**
 *  linear_search - Search for a value in an array of integer using linear search
 *  @array: A pointer to the first element of the array to search
 *  @size: The number of elements in the array
 *  @value: Value to search for.
 *
 *  REturn: If the value is not peresent or the array is NULL, -1. otherwise,the first index where the value is located
 *
 */
int linear_search(int *array,size_t size,int value)
{
	size_t i;

	/*check if the array is NULL */
	if (array == NULL)
		return (-1);
        /*Iterate over each element of the array */
	for (i = 0; i < size;i++)
	{ 
		/*Print the value being checked*/
		printf("Value checked array[%ld] - [%d]\n",i,array[i]);

		/* if the value is found */
		if (array[i] == value)
			/*Return the index of the value */
			return (i);
	}
	/* Value not found, return -1 */ 
	return (-1);
}
