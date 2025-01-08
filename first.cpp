#include<bits/stdc++.h>
using namespace std;

void hashfun(int hashT[], int n, int value) {
    int loc = value % n; // Calculate hash index
    while (hashT[loc] != -1) { // Perform linear probing
        loc = (loc + 1) % n;
    }
    hashT[loc] = value; // Place the value in the hash table
}

bool search(int hashT[], int n, int value) {
    int loc = value % n; // Calculate hash index
    int start = loc; // Save the starting location to detect cycles
    while (hashT[loc] != -1) {
        if (hashT[loc] == value) {
            return true; // Value found
        }
        loc = (loc + 1) % n; // Move to the next slot
        if (loc == start) {
            break; // Avoid infinite loop if we circle back to the start
        }
    }
    return false; // Value not found
}

void deleteElement(int hashT[], int n, int value) {
    int loc = value % n; // Calculate hash index
    int start = loc; // Save the starting location to detect cycles
    while (hashT[loc] != -1) {
        if (hashT[loc] == value) {
            hashT[loc] = -2; // Mark the slot as deleted (using -2 to indicate deleted slots)
            cout << "Value " << value << " deleted from the hash table.\n";
            return;
        }
        loc = (loc + 1) % n; // Move to the next slot
        if (loc == start) {
            break; // Avoid infinite loop if we circle back to the start
        }
    }
    cout << "Value " << value << " not found in the hash table.\n";
}

void print(int hashT[], int n) {
    for (int i = 0; i < n; i++) {
        if (hashT[i] == -1) {
            cout << "-1 "; // Empty slot
        } else if (hashT[i] == -2) {
            cout << "-2 "; // Deleted slot
        } else {
            cout << hashT[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the hash table: ";
    cin >> n;

    int hashT[n];
    for (int i = 0; i < n; i++) {
        hashT[i] = -1; // Initialize hash table with -1 (indicating empty slots)
    }

    int num_elements;
    cout << "Enter the number of elements to insert: ";
    cin >> num_elements;

    cout << "Enter the elements: \n";
    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        hashfun(hashT, n, value); // Insert element into the hash table
    }

    cout << "Hash table after linear probing: \n";
    print(hashT, n);

    int search_value;
    cout << "Enter the value to search: ";
    cin >> search_value;

    if (search(hashT, n, search_value)) {
        cout << "Value " << search_value << " found in the hash table.\n";
    } else {
        cout << "Value " << search_value << " not found in the hash table.\n";
    }

    int delete_value;
    cout << "Enter the value to delete: ";
    cin >> delete_value;

    deleteElement(hashT, n, delete_value); // Delete the specified element

    cout << "Hash table after deletion: \n";
    print(hashT, n);

    return 0;
}
