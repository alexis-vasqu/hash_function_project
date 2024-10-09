#include "hash.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructor: initializes the hash table with a given number of slots (k)
HashTable::HashTable(int size) {
    k = size;
    table = new Node*[k];  // Allocate an array of pointers to Node structs
    for (int i = 0; i < k; i++) {
        table[i] = nullptr;  // Initialize all slots to nullptr (empty linked lists)
    }
}

// Custom hash function to hash based on the first character of the string
int HashTable::hash_function(string text) {
    // A simple hash function: use the ASCII value of the first character of the string
    return (tolower(text[0]) - 'a') % k;
}

// Insert a token into the hash table
void HashTable::insert(string key) {
    int index = hash_function(key);  // Get the index using the hash function

    // Create a new node for the key
    Node* new_node = new Node(key);

    // If the slot is empty, insert the new node directly
    if (table[index] == nullptr) {
        table[index] = new_node;
    }
    // Otherwise, append the new node to the beginning of the linked list (chaining)
    else {
        new_node->next = table[index];
        table[index] = new_node;
    }
}

// Print the contents of the first 5 slots
void HashTable::print_slots() {
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Slot " << i << ": ";
        Node* current = table[i];  // Traverse the linked list at this slot
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Print the lengths of all slots
void HashTable::print_slot_lengths() {
    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < k; i++) {
        int length = 0;
        Node* current = table[i];
        // Count the number of nodes in the linked list
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << length << endl;
    }
}

// Calculate and print the standard deviation of the slot lengths
void HashTable::print_standard_deviation() {
    double mean = 0;
    double variance = 0;

    // Calculate the mean (average) length of slots
    for (int i = 0; i < k; i++) {
        int length = 0;
        Node* current = table[i];
        // Count the number of nodes in the linked list
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        mean += length;
    }
    mean = mean / k;

    // Calculate the variance
    for (int i = 0; i < k; i++) {
        int length = 0;
        Node* current = table[i];
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        variance += pow(length - mean, 2);
    }
    variance = variance / k;

    // Standard deviation is the square root of the variance
    double stddev = sqrt(variance);
    cout << "==== Printing the standard deviation =====" << endl;
    cout << stddev << endl;
}

// Destructor: cleans up the memory used by the hash table
HashTable::~HashTable() {
    // Delete all the nodes in the linked lists
    for (int i = 0; i < k; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    // Delete the table itself
    delete[] table;
}
