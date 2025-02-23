//  Module 3
//
//  Created by Luke Contreras on 2/23/25.
//
// pointersArePowerful.cpp
#include <iostream>
using namespace std;

int main() {
    // === Pointer Basics ===
    int a = 100;        // Declare an integer variable with a new value.
    int* p = &a;        // Declare a pointer and assign the address of 'a'.
    
    cout << "=== Pointer Basics ===" << endl;
    cout << "Address stored in pointer p: " << p << endl;
    cout << "Value of a using pointer p: " << *p << endl;
    
    // Change the value of 'a' using the pointer.
    *p = 200;
    cout << "New value of a after modification: " << a << endl << endl;
    
    // === Pointer Arithmetic ===
    int arr[5] = {11, 22, 33, 44, 55};  // Create an array of 5 integers with new values.
    int* ptr = arr;                     // Pointer to the first element of the array.
    
    cout << "=== Pointer Arithmetic ===" << endl;
    for (int i = 0; i < 5; i++) {
        // Print the address of the current element using pointer arithmetic.
        cout << "Address of arr[" << i << "]: " << (ptr + i) << endl;
        // Print the value of the current element.
        cout << "Value of arr[" << i << "]: " << *(ptr + i) << endl;
    }
    
    return 0;
}

