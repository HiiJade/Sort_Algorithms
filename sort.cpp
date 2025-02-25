#include <iostream>
#include <chrono>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> sizes = {10, 20, 50, 100, 500, 1000, 5000, 10000};
    for (int n : sizes) {
        std::vector<int> arr(n);
        for (int& x : arr) x = rand() % 10000;
        
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(arr);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "Insertion Sort, n=" << n << " Time: "
                  << std::chrono::duration<double>(end - start).count() << " s\n";

        for (int& x : arr) x = rand() % 10000;
        start = std::chrono::high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Merge Sort, n=" << n << " Time: "
                  << std::chrono::duration<double>(end - start).count() << " s\n";
    }
    return 0;
}
