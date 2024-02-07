#include<stdio.h>
 
/*8
 * key_index - gives index of a key
 * @key: key to get index for
 * @size: size of the hash table
 *
 * Return : index for the key
 */
unsigned long int key_inde(const unsigned char *key,unsigned long int size)
{
	return (hash_djb2(key) % size);
}
