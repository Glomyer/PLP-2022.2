#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct Data {
  char *name;
  char *type;
  char *value;
};

struct Entry {
  char *key;
  struct Data *data;
  struct Entry *next;
};

struct HashTable {
  struct Entry **table;
};

struct HashTable *create_hash_table() {
  struct HashTable *ht = malloc(sizeof(struct HashTable));
  ht->table = malloc(sizeof(struct Entry*) * TABLE_SIZE);
  for (int i = 0; i < TABLE_SIZE; i++) {
    ht->table[i] = NULL;
  }
  return ht;
}

unsigned int hash(struct HashTable *ht, char *key) {
  unsigned int hash = 5381;
  int c;
  while ((c = *key++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash % TABLE_SIZE;
}

struct Entry *create_entry(char *key, struct Data *data) {
  struct Entry *entry = malloc(sizeof(struct Entry));
  entry->key = strdup(key);
  entry->data = data;
  entry->next = NULL;
  return entry;
}

void set(struct HashTable *ht, char *key, struct Data *data) {
  unsigned int index = hash(ht, key);
  struct Entry *entry = create_entry(key, data);
  entry->next = ht->table[index];
  ht->table[index] = entry;
}

struct Data *get(struct HashTable *ht, char *key) {
  unsigned int index = hash(ht, key);
  struct Entry *entry = ht->table[index];
  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      return entry->data;
    }
    entry = entry->next;
  }
  return NULL;
}

void del(struct HashTable *ht, char *key) {
  unsigned int index = hash(ht, key);
  struct Entry *entry = ht->table[index];
  struct Entry *prev = NULL;
  while (entry) {
    if (strcmp(entry->key, key) == 0) {
      if (prev) {
        prev->next = entry->next;
      } else {
        ht->table[index] = entry->next;
      }
      free(entry->key);
      free(entry->data);
      free(entry);
      return;
    }
    prev = entry;
    entry = entry->next;
  }
}
