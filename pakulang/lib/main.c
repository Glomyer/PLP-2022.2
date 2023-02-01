#include <stdio.h>
#include "hash_table.h"


int main() {
  struct Data* teste = malloc(sizeof(struct Data));
  
  teste->name = "nome";
  teste->type = "*char";
  teste->value = "Luiz";
  




  struct HashTable *ht = create_hash_table();
  set(ht, "key1", teste);
  struct Data* dados = get(ht, "key1");
  printf("%s %s %s\n",dados->name, dados->type, dados->value);

  dados = get(ht, "key2");

  if(dados == NULL){
    printf("Dados nulo\n");
    return 0;
  }
  
  printf("%s %s %s\n",dados->name, dados->type, dados->value);
  return 0;

  /*
  set(ht, "key2", "Python");
  set(ht, "key3", "Nintendo");
  printf("%s\n", get(ht, "key1"));
  printf("%s\n", get(ht, "key2"));
  printf("%s\n", get(ht, "key3"));
  del(ht, "key2");
  return 0;
  */
}