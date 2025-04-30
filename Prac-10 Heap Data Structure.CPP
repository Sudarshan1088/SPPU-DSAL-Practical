#include <iostream>
using namespace std;

// MaxHeapify function to maintain the max-heap property
void MaxHeapify(int a[], int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n) {
        if (j < n && a[j + 1] > a[j])
            j = j + 1;
        if (temp > a[j])
            break;
        a[j / 2] = a[j];
        j = 2 * j;
    }
    a[j / 2] = temp;
}

// MinHeapify function to maintain the min-heap property
void MinHeapify(int a[], int i, int n) {
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n) {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;
        if (temp < a[j])
            break;
        a[j / 2] = a[j];
        j = 2 * j;
    }
    a[j / 2] = temp;
}

// MaxHeapSort to sort the array in ascending order using Max Heap
void MaxHeapSort(int a[], int n) {
    int temp;
    for (int i = n; i >= 2; i--) {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MaxHeapify(a, 1, i - 1);
    }
}

// MinHeapSort to sort the array in descending order using Min Heap
void MinHeapSort(int a[], int n) {
    int temp;
    for (int i = n; i >= 2; i--) {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        MinHeapify(a, 1, i - 1);
    }
}

// Function to build a Max Heap
void Build_MaxHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--)
        MaxHeapify(a, i, n);
}

// Function to build a Min Heap
void Build_MinHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--)
        MinHeapify(a, i, n);
}

int main() {
    int n;
    cout << "Enter the number of subjects of second year: ";
    cin >> n;
    
    n++; // Adjusting for 1-based indexing
    int arr[n];
    
    // Input marks for each subject
    for (int i = 1; i < n; i++) {
        cout << "Enter the marks for subject " << i << ": ";
        cin >> arr[i];
    }

    // Build and sort using Max Heap
    Build_MaxHeap(arr, n - 1);
    cout << "\nArray after building MaxHeap: ";
    for (int i = 1; i < n; i++) 
        cout << arr[i] << " ";
    
    MaxHeapSort(arr, n - 1);
    cout << "\nSorted Data (Ascending Order): ";
    for (int i = 1; i < n; i++) 
        cout << arr[i] << " ";

    // Find the minimum marks (first element after MaxHeapSort)
    int min = arr[1];

    // Build and sort using Min Heap
    Build_MinHeap(arr, n - 1);
    cout << "\nArray after building MinHeap: ";
    for (int i = 1; i < n; i++) 
        cout << arr[i] << " ";
    
    MinHeapSort(arr, n - 1);
    int max = arr[1];

    // Display the sorted data in descending order
    cout << "\nSorted Data (Descending Order): ";
    for (int i = 1; i < n; i++) 
        cout << arr[i] << " ";

    // Output the maximum and minimum marks
    cout << "\nMaximum Marks: " << max << "\nMinimum Marks: " << min;

    return 0;
}
