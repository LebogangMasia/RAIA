#ifndef RYTHON_TABLE_HPP
#define RYTHON_TABLE_HPP
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>

struct HashTableItem {
    char* key;
    char* value;
};

struct HashTable {
    HashTableItem** items; // pointer to hashtable items;
    int size; // max number of items
    int count;
};

int HashFunction(char* key, char* value);
HashTableItem* createItem(char* key, char* value);
HashTable* createTable(int size);

// HashTable algorithms
void HashTableInsert(HashTable* table, char* key, char* value);
void printTable(HashTable* table);  // print table

// memory management
void freeItems(HashTableItem* items);
void freeTable(HashTable* table);


#endif // RYTHON_TABLE_HPP