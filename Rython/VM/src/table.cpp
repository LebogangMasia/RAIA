#include "../include/table.hpp"

int HashFunction(char* key, char* value) {
   char* buffer = new char[strlen(type) + strlen(value) + 1 + 1];
    strcpy(buffer, type);
    strcat(buffer, value);

    int i = 0;
    for(int j=0;buffer[j];j++)
        i += buffer[j];

    return i % 50000;
}


HashTableItem* createItem(char* key, char* value) {
    auto* item = (HashTableItem*) malloc(sizeof(HashTableItem));
    item->key = (char*)malloc(strlen(key));
    item->value = (char*)malloc(strlen(value));

    item->key = key;
    item->value = value;

    return item;
}

HashTable* createTable(int size) {
    auto* table = (HashTable*) malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    
    for (int i=0;i<table->size;i++) 
        table->items[i] = NULL;

    return table;
}

void HashTableInsert(HashTable* table, char* key, char* value) {
    int index = HashFunction(key, value);
    HashTableItem* item = createItem(key, value);
    HashTableItem* current_item = table->items[index];

    if (current_item == NULL) {
        if (table->count == table->size) {
            printf("Insert Error: Hash Table is full");
            freeItems(item);
            return;
        }

        table->items[index] = item;
        table->count++;
    }
}

void printTable(HashTable* table) {
    printf("\n--------------------------------Hash Table--------------------------------\n");
    for (int i=0;i<table->size;i++) {
        if (table->items[i])
            printf("Key: %s\t\tValue: %s", table->items[i]->key, table->items[i]->value);
    }

    printf("--------------------------------------------------------------------------\n");
}

void freeItems(HashTable* item) {
    free(item->key);
    free(item->value);
    free(item);
}

void freeTable(HashTable* table) {
    for (int i=0;i<table->size;i++)
        freeItems(table->item[i]);

    free(table->size);
    free(table->count);
}