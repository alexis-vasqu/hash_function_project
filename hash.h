#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Define the Node structure for the linked list (chaining)
struct Node {
    string key;
    Node* next;

    Node(string k) : key(k), next(nullptr) {}
};

// Hash Table Class
class HashTable {
private:
    int slots; // Number of slots in the hash table
    Node** table; // Pointer to an array of pointers to linked lists

public:
    HashTable(int k);
    ~HashTable();
    int hash_function(string text);
    void insert(string key);
    void printTable();
    void printSlotLengths();
    float calculateStandardDeviation();
};

#endif // HASH_H
