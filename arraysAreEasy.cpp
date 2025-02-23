
//  Module 3
//
//  Created by Luke Contreras on 2/23/25.
//
// arraysAreEasy.cpp
#include <iostream>
using namespace std;

int main() {
    // Declare a 3-D array with dimensions 2 x 3 x 4
    int arr[2][3][4];

    // Initialize the 3-D array with sequential values
    int value = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                arr[i][j][k] = value++;
            }
        }
    }

    // Display the 3-D array
    for (int i = 0; i < 2; i++) {
        cout << "Layer " << i << ":\n";
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}

