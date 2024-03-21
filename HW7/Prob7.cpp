#include<iostream>
using namespace std;

void printArray(int arr[], int size);


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { 
        cout << "Step " << i << ": ";
        printArray(arr,n);        // loop through the array elements
        for (int j = 0; j < n - i - 1; j++) { // last i elements are already in place
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j + 1] if they are in wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int dataset[] = {23, 78, 45, 8, 32, 56};
    int n = sizeof(dataset) / sizeof(dataset[0]);
    bubbleSort(dataset, n);

    cout << "Sorted array:\n";
    printArray(dataset, n);

    return 0;
}