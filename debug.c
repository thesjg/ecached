#include "debug.h"
#include "hash.h"

void
print_storage()
{
    cache_object_t co;

    for (int i = 0; i < active_tables; ++i) {
        const hash_table_t ht = table[i];
        for (int j = 0; j < (1<<HASH_START_SIZE); ++j) {
            hash_entry_t he = (hash_entry_t)(*((uintptr_t *)&ht->table[j]));
            if (he != NULL) {
                printf("Bucket: %d Keys: ", j);
                for (hash_keylen_t k = 0; k < he->len; ++k) {
                    printf("%c", he->key[k]);
                    if (k == he->len - 1) printf(" ");
                }
                printf("\n");
                co = (cache_object_t)he->data;
                printf("\tSize: %d, Flags: %d, Refcnt: %d, Buckets: %d\n",
                       co->size, co->flags, co->refcnt, co->buckets);
            }
        }        
    }
}

void
test()
{
    char *foo = "FOO";
    char *bar = "BAR";

    hash_insert(hash("foo", 3), "foo", 3, foo);
    hash_insert(hash("bar", 3), "bar", 3, bar);

    printf("%08x %08x\n", (uint)foo, (uint)bar);
    printf("%08x %08x\n", (uint)(hash_search(hash("foo", 3), "foo", 3))->data,
                          (uint)(hash_search(hash("bar", 3), "bar", 3))->data);
}
