

/**
 * @brief
 * This is my second trial to implement hash table.
 * what is the approach i'm going to use to avoid collision.
 *
 * Hash table is used for fast looking up approx `O(1)`
 */
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
// ======================= Utils ====================================
#define TABLE_SIZE 30 // just 30 slots
// hash function
unsigned long hash_function(char *key)
{
    unsigned long int value = 0;
    unsigned int key_len = strlen(key);

    for (unsigned int i = 0; i < key_len; i++)
    {
        value = value * 37 + key[i];
    }
    value = value % TABLE_SIZE;
    return value;
}
// ======================= Linear prob approach ======================
// item frame
typedef struct
{
    char *key;
    void *value;

} item;

// hashtable construction
typedef struct
{
    unsigned int n_items;
    unsigned int capacity;
    item *entries; // pointer to array of pointers to items.
} hashTable;

#define INITIAL_CAPACITY 16
// ht creation
hashTable *create_ht()
{
    hashTable *ht = malloc(sizeof(hashTable));
    ht->n_items = 0;
    ht->capacity = INITIAL_CAPACITY;

    ht->entries = calloc(ht->capacity, sizeof(item));
    if (ht->entries == NULL)
    {
        free(ht);
        return NULL;
    }
    return ht;
}

const char *item_set(item *entries, unsigned int capacity, const char *key, void *value, unsigned int plength)
{

    // get the hash value of the key
    index = hash_function(key);
    // go through keys to find if the provided key is available in ht entries
    while (entries[index].key != NULL)
    {
        // if so update the value of the given key
        if (strcmp(entries[index].key) == 0)
        {
            entries[index].value = value;
            return entries[index].key;
        }
        index++;
        if (index >= capacity)
        {
            index = 0;
        }
    }

    // if not, create new item with the provided key
    if(plength != NULL)
    {
        key = strdup(key);
        if(key == NULL)
        {
            return NULL;
        }
        // update number of elements and the capacity
        (*plength)++;
    }
    entries[index].key = key;
    entries[index].value = value;
    return key;
}

void expand_ht(hashTable *ht)
{
    ht->capacity = ht->capacity * 2;
    ht->entries = realloc(ht->entries, sizeof(void *) * ht->capacity);
}

void ht_set(hashTable *ht, item *item)
{
    // If length will exceed half of current capacity, expand it.
    if (ht->n_items >= ht->capacity / 2)
    {
        // expand ht
        expand_ht(ht);
    }
}

// ======================= chaining approach ======================
void main()
{
    hashTable *ht = create_ht();
    char word[101];
    scanf("%100s", word);
    int *pcount = malloc(sizeof(int));

    item *item1;

    // printf("content of key1 = %s \n", key1);

    // printf("Address of key1 = %p \n", *key1);
    // printf("Content of address of key1 = %s \n", *(key1));

    item1->key = word;
    item1->value = &value1;

    ht_set(ht, &item1);
}
