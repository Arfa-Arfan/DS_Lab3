#include <iostream>
using namespace std;

// Class to wrap dynamic array operations and manage memory
class ArrayWrapper {
private:
    int* data;    // Raw pointer to the dynamic array
    int size;     // Current size of the array

public:
    // Constructor: Takes size 'n', allocates memory, and initializes elements
    ArrayWrapper(int n) : size(n) {
        // Dynamic Allocation: Use 'new int[n]' to reserve memory on the heap
        data = new int[size];  // Allocate memory for array of given size
        cout << "Dynamic ArrayWrapper created successfully with size " << size << "." << endl;
        
        // Initialize values with pattern: i*10 + 5
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10 + 5;  // Set values: 5, 15, 25, 35, etc.
        }
    }

    // Destructor: CRITICAL for cleaning up dynamically allocated memory
    ~ArrayWrapper() {
        // Memory Management: Use 'delete[]' to free the entire array block
        delete[] data;
        data = nullptr;  // Prevent dangling pointers by setting to null
        cout << "ArrayWrapper memory freed safely. (Destructor called)" << endl;
    }

    // Method to read an element by index (O(1) access)
    int getElement(int index) const {
        // Check if index is within valid range
        if (index >= 0 && index < size) {
            return data[index];  // Return element at specified index
        }
        return -1;  // Return error value for invalid index
    }

    // Method to print the entire array
    void print() const {
        cout << "Wrapper Array: [ ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << (i == size - 1 ? "" : ", ");  // Print with comma separation
        }
        cout << " ]" << endl;
    }
};

int main() {
    cout << "--- Task 1 Demonstration ---" << endl;
    
    // Create ArrayWrapper object with size 4
    ArrayWrapper wrapper(4);
    wrapper.print();  // Print the entire array
    
    // Access and display element at index 2
    cout << "Element at index 2: " << wrapper.getElement(2) << endl;
    
    // Destructor will be called automatically when 'wrapper' goes out of scope
    return 0;
}