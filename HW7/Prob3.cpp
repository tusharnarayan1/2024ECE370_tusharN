#include <iostream>
#include <vector>

void printArray(const std::vector<int>& arr);


// Function to perform selection sort
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Find the minimum element in unsorted array
        int min_index = i;
        std::cout << "Step " << i << ": ";
        printArray(arr);
        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[min_index])
                min_index = j;

        // Swap the found minimum element with the first element
        std::swap(arr[min_index], arr[i]);
    }
}

// Function to print an array
void printArray(const std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    // Given dataset
    std::vector<int> dataset = {23, 78, 45, 8, 32, 56};

    // Sorting array using selection sort
    selectionSort(dataset);

    std::cout << "Sorted array: ";
    printArray(dataset);

    return 0;
}