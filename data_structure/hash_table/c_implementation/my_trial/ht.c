#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *key;
    void *value;
} ht_entry;

struct ht
{
    ht_entry *entries; // hash table slots.

    size_t length;   // number of items in the hash table.
    size_t capacity; // size of the entries array.
};

#define INITIAL_CAPACITY 16

ht *create_ht(void)
{
    ht *table = malloc(sizeof(ht));

    if (table == NULL)
    {
        return NULL;
    }

    table->length = 0;
    table->capacity = INITIAL_CAPACITY;

    table->entries = calloc(table->capacity, sizeof(ht_entry));

    if (table->entries == NULL)
    {
        free(table);
        return NULL;
    }
    return table;
}

void* destroy_ht(ht* table)
{
    for (int i = 0; i<table->capacity; i++)
    {
        if(table->entries[i].key != NULL)
        {
            free((void *)table->entries[i].key);
        }
    }

    free(table->entries);
    free(table);
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated). See description:
// https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function 
static uint64_t hash_key(const char* key) {

    uint64_t hash = FNV_OFFSET;
    // TODO: why such condition is just the content of the key?
    // is the last one be null, or garbage.
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

void* ht_get(ht* table, char* key)
{
    // you need to compute the hash value of the key first.
    uint64_t hashed_value = hash_key(key)
    size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

    while (table->entries[i].key != NULL)
    {
        if(strcmp(table->entries[index].key, key) == 0)
        {
            return table->entries[index].value;
        }
        // as we are using a linear prop
        index++;
        if (index >= table->capacity){
            index = 0;
        }
    }
    return NULL;
}

char* ht_set(ht* table, char* key, void *value)
{
    uint64_t hash = hash_key(key);
    size_t index = (size_t)(hash & (uint64_t)(table->capacity - 1));

    // two possible scenarios 
    // update a the provided key's value.
    // define a new item.
    while(table->entries[index].key != NULL)
    {
        if(strcmp(key, table->entries[index].key) == 0)
        {
            table->entries[index].value = value;
            return table->entries[index].key;
        }

        index++;
        if(index >= table->capacity)
        {
            index = 0;
        }
    }

    if(table->length != NULL)
    {
        key = strdup(key);
        if(key == NULL)
        {
            return NULL;
        }
        (*(table->length))++;
    }
    table->entries[index].key = key;
    table->entries[index].value = value;
    return key;
}





