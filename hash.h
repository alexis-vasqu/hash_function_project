#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Node struct to store each token and a pointer to the next node (linked list)
struct Node {
    string key;  // The token or key
    Node* next;  // Pointer to the next node in the list

    // Constructor to create a new node
    Node(string k) : key(k), next(nullptr) {}
};

class HashTable {
private:
    int k;          // Number of slots in the hash table
    Node** table;   // Array of pointers to linked lists (chaining)

public:
    HashTable(int size);  // Constructor
    int hash_function(string text);  // Custom hash function
    void insert(string key);  // Insert a key into the hash table
    void print_slots();  // Print the first 5 slots
    void print_slot_lengths();  // Print the lengths of each slot
    void print_standard_deviation();  // Print the standard deviation of slot lengths
    ~HashTable();  // Destructor to clean up memory
};

