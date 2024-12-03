#include <bits/stdc++.h>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        ++comparisons; // Increment comparisons
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to randomize pivot and partition the array
int randomizedPartition(int arr[], int low, int high, int& comparisons) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[randomPivotIndex], arr[high]);
    return partition(arr, low, high, comparisons);
}

// Randomized Quick Sort function
void randomizedQuickSort(int arr[], int low, int high, int& comparisons) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high, comparisons);
        randomizedQuickSort(arr, low, pi - 1, comparisons);
        randomizedQuickSort(arr, pi + 1, high, comparisons);
    }
}

// Main function to test the implementation
int main() {
    srand(time(0)); // Seed the random number generator

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int comparisons = 0;
    randomizedQuickSort(arr, 0, n - 1, comparisons);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}

