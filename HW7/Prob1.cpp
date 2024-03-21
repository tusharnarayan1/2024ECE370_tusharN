#include <iostream>
#include <vector>

// Function to perform binary search on dataset
int binarySearch(std::vector<int>& data, int target) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (data[mid] == target) {
            return mid; // Target found, return index
        }

        // If target greater, ignore left half
        if (data[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }
    
    // Target was not found
    return -1;
}

int main() {
    std::vector<int> dataset = {0, 1, 2, 3, 4, 5, 6};
    int target = 6; // Element to search for

    int result = binarySearch(dataset, target);

    if (result != -1) {
        std::cout << "Element " << target << " found at index " << result << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the dataset." << std::endl;
    }

    return 0;
}