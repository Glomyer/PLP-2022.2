#include <stdio.h>
#include "hash_table.h"

int main() {
  struct HashTable *ht = create_hash_table();
  set(ht, "key1", "Computação");
  set(ht, "key2", "Python");
  set(ht, "key3", "Nintendo");
  printf("%s\n", get(ht, "key1"));
  printf("%s\n", get(ht, "key2"));
  printf("%s\n", get(ht, "key3"));
  del(ht, "key2");
  printf("%s\n", get(ht, "key2"));
  return 0;
}