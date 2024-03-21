#include <iostream>
#include <vector>

void printArray(const std::vector<int> &arr);

void insertionSort(std::vector<int> &arr) {
    int i, j, key;
    for (i = 1; i < arr.size(); i++) {
        key = arr[i]; // The element to be inserted in the sorted part of the array
        j = i - 1;
        std::cout << "Step " << i << ": ";
        printArray(arr);
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Place key at after the element just smaller than it
    }
}

void printArray(const std::vector<int> &arr) {
    for (int num : arr)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> dataset = {23, 78, 45, 8, 32, 56};

    insertionSort(dataset);

    std::cout << "Sorted dataset: ";
    printArray(dataset);

    return 0;
}