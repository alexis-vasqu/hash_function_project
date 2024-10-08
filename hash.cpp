#include "hash.h"

// Constructor to initialize the hash table with given number of slots
HashTable::HashTable(int k) {
    this->slots = k;
    table = new Node*[k];
    for (int i = 0; i < k; i++) {
        table[i] = nullptr;
    }
}

// Destructor to free up memory used by the hash table
HashTable::~HashTable() {
    for (int i = 0; i < slots; i++) {
        Node* current = table[i];
        while (current != nullptr) {
            Node* prev = current;
            current = current->next;
            delete prev;
        }
    }
    delete[] table;
}

// Hash Function (You can improve this to suit your needs)
int HashTable::hash_function(string text) {
    int hash = 0;
    for (char ch : text) {
        hash = (hash * 31 + ch) % slots; // Using a simple polynomial hash function
    }
    return hash;
}

// Insert a key into the hash table
void HashTable::insert(string key) {
    int slot = hash_function(key);
    Node* newNode = new Node(key);
    
    // Insert new node at the beginning of the linked list
    newNode->next = table[slot];
    table[slot] = newNode;
}

// Print the first 5 slots of the hash table
void HashTable::printTable() {
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5 && i < slots; i++) {
        cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current != nullptr) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Print the length of each slot (number of elements in each linked list)
void HashTable::printSlotLengths() {
    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < slots; i++) {
        int length = 0;
        Node* current = table[i];
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << length << endl;
    }
}

// Calculate the standard deviation of slot lengths
float HashTable::calculateStandardDeviation() {
    // Calculate the mean of the slot lengths
    float sum = 0;
    int* lengths = new int[slots];
    for (int i = 0; i < slots; i++) {
        int length = 0;
        Node* current = table[i];
        while (current != nullptr) {
            length++;
            current = current->next;
        }
        lengths[i] = length;
        sum += length;
    }
    
    float mean = sum / slots;
    
    // Calculate the variance
    float variance = 0;
    for (int i = 0; i < slots; i++) {
        variance += pow(lengths[i] - mean, 2);
    }
    variance /= slots;
    
    delete[] lengths; // Free up memory
    
    // Return the square root of the variance (standard deviation)
    return sqrt(variance);
}
