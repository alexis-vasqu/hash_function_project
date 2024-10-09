/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Alexis Vasquez
Your team alias: MMI
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // Create a hash table with k slots
    HashTable hashTable(k);

    // Insert all the tokens into the hash table
    for (int i = 0; i < n; i++) {
        hashTable.insert(texts[i]);
    }

    // Print the contents of the first 5 slots
    hashTable.print_slots(); // Updated to match hash.cpp

    // Print the lengths of all slots
    hashTable.print_slot_lengths(); // Updated to match hash.cpp

    // Calculate and print the standard deviation of slot lengths
    hashTable.print_standard_deviation(); // Updated to match hash.cpp

    return 0;
}

