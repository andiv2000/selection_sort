//
// Created by Andrei Vitan on 5/11/2024.
//
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Schimbarea elementelor
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    const int size = 10000;
    int arr[size];

    // Generarea array-ului cu valori aleatorii
    srand(time(NULL)); // Inițializarea generatorului de numere aleatoare
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000; // Generare de valori aleatorii între 0 și 9999
        //cout<<arr[i]<<" ";
    }

    // Măsurarea timpului pentru sortare
    clock_t start = clock();
    selectionSort(arr, size);
    clock_t end = clock();

    // Calcularea timpului total de sortare
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by selection sort: " << time_taken << " seconds" << endl;

    return 0;
}
