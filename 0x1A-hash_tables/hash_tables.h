#ifdef _HASH_TABLE_H_
#define _HASH_TABLE_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * struct hash_node_s-Node of a hash table
 *
 * @key:The key,string 
 * The:key is unique is the HashTable
 * @value:The value corresponding to a key 
 * @next :Apointer to the next node of the List 
 */
typedef struct hash_node_s
{
      char *Key;
      char *value;
      struct hash_node_s *next;
}hash_node_t;
/**
 * struct hash_table_s-Hash table data structure
 *
 * @size: The size of the array
 * @array:An array of size @size
 * Each call of this array is apointer to the first node a linkrd list,
 *because we want our HashTable to use a chasing collission handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_table_t **array;
}hash_table_t;
hash_table_t *hash_table_create(unsigned long int size);
unsigned long int hash_djb2(const unsigned char *str);
unsigned long int key_index(const unsigned char *key,unsigned long int size);
int hash_table_set(hash_table_t *ht,const char *key,const char *value);
char *hash_table_get(const hash_table_t *ht,const char *key);
void hash_table_print(const  hash_=_tabke_t *ht);
void hash_table_delete(hash_table_t *ht);
#endif /*_HASH_TABLE_#_*/
