#include <iostream>
using namespace std;

#define MAX_SIZE 5  // Define maximum size for the stack

// Implement the Stack ADT using a static array
class StackArray {
private:
    int data[MAX_SIZE];  // Static array for storage (Fixed size)
    int top;             // Index of the top element (LIFO tracking)

public:
    // Constructor: Initializes the stack object
    StackArray() : top(-1) {
        cout << "StackArray initialized (MAX size: " << MAX_SIZE << ")" << endl;
    }

    // Method 1: Push (Adding an element to the stack)
    void push(int val) {
        // Check for Overflow (Array is full)
        if (top == MAX_SIZE - 1) {
            cout << "\nERROR: STACK OVERFLOW! Cannot push " << val << " (Array is full)." << endl;
            return;  // Exit if stack is full
        }
        // O(1) Push: Move top pointer up, then store value
        data[++top] = val;
        cout << "Pushed: " << val << endl;
    }

    // Method 2: Pop (Removing the top element)
    int pop() {
        // Check for Underflow (Stack is empty)
        if (top == -1) {
            cout << "\nERROR: STACK UNDERFLOW! (Stack is empty)." << endl;
            return -1;  // Return error value
        }
        // O(1) Pop: Return data at top, then move top pointer down
        return data[top--];
    }

    // Method 3: Peek (View the top element without removing it)
    int peek() const {
        if (top == -1) return -1;  // Return -1 if stack is empty
        return data[top];  // Return top element without removing
    }

    // Helper to print the stack state
    void print() const {
        cout << "StackArray (TOP->BOT): [ ";
        // Print from top to bottom (LIFO order)
        for (int i = top; i >= 0; --i) {
            cout << data[i] << (i == 0 ? "" : ", ");
        }
        cout << " ]" << endl;
    }
};

int main() {
    cout << "--- Task 2 Demonstration ---" << endl;
    StackArray stack;
    
    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);  // This should trigger Overflow error
    
    stack.print();  // Print current stack state
    
    // Pop an element and display
    cout << "Popped value: " << stack.pop() << endl;
    stack.print();  // Print stack after pop operation
    
    return 0;
}