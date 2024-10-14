#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Node struct to store each token and pointer to next node (linked list)
struct Node {
    string key;  // key
    Node* next;  // Pointer to next node in the list

    // Constructor for new node
    Node(string k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    int slots;          // Number of slots in the hash table
    Node** table;   // Array of pointers (chaining)

public:
    HashTable(int size);  // Constructor
    int hash_function(string text);  // Custom hash function
    void insert(string key);  // Insert key into the hash table
    void printTable();  // Print first 5 slots
    void printSlotLengths();  // Print lengths of each slot
    float calculateStandardDeviation();  // Calculate sd of slot lengths
    ~HashTable();  //  clean up
};

#endif
