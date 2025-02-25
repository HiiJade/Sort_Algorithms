**Sort Algorithms Performance Analysis**

**Overview**

This project compares the execution time of **Merge Sort** and **Insertion Sort** for different input sizes. The program measures the sorting time using std::chrono::high_resolution_clock in C++.

**Algorithms Implemented**

1. **Merge Sort**

    A divide and conquer algorithm with a time complexity of O(n log n).

    Recursively splits the array into two halves, sorts them, and merges them back.

2. **Insertion Sort**

    A simple sorting algorithm with a time complexity of O(n^2).

    Efficient for small input sizes due to its low overhead and cache efficiency.

**Features**

✅ Implements Merge Sort and Insertion Sort in C++.
✅ Measures execution time for various input sizes.
✅ Uses std::vector<int> for handling dynamic arrays.
✅ Outputs sorting time for different values of n.

**Code Structure**

    mergeSort(): Implements the Merge Sort algorithm.

    merge(): Merges two sorted subarrays.

    insertionSort(): Implements the Insertion Sort algorithm.

    main(): Runs sorting algorithms on different input sizes and measures execution time.

**How to Compile and Run**

    Using g++ (GCC)

# Compile the program
    g++ -O2 -std=c++17 sort.cpp -o sort_algorithms

# Run the executable
    ./sort_algorithms


