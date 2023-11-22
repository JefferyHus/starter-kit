**1. Find the Maximum and Minimum Values in an Array:**

```c
#include <iostream>

void findMinMax(int arr[], int n, int& min, int& max) {
    min = INT_MAX;  // Initialize min to the maximum possible value
    max = INT_MIN;  // Initialize max to the minimum possible value

    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}

int main() {
    int arr[] = {3, 9, 1, 6, 4, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    findMinMax(arr, n, min, max);

    std::cout << "Minimum: " << min << std::endl;
    std::cout << "Maximum: " << max << std::endl;

    return 0;
}
```

**Explanation:** In this solution, we initialize `min` to the maximum possible integer value (`INT_MAX`) and `max` to the minimum possible integer value (`INT_MIN`). We then iterate through the array, updating `min` and `max` as we find smaller and larger values. After the loop, `min` will contain the minimum value in the array, and `max` will contain the maximum value.

**2. Find Duplicates in an Array:**

```c
#include <iostream>
#include <unordered_set>

void findDuplicates(int arr[], int n) {
    std::unordered_set<int> seen;
    std::cout << "Duplicate elements in the array: ";
    
    for (int i = 0; i < n; i++) {
        if (seen.find(arr[i]) != seen.end()) {
            std::cout << arr[i] << " ";
        } else {
            seen.insert(arr[i]);
        }
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {3, 9, 1, 6, 4, 8, 2, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, n);

    return 0;
}
```

**Explanation:** In this solution, we use an `unordered_set` to keep track of elements we have seen so far. We iterate through the array, and for each element, we check if it's already in the set. If it is, we print it as a duplicate; otherwise, we insert it into the set.

**3. Rotate an Array:**

```c
#include <iostream>

void rotateArray(int arr[], int n, int k) {
    int temp[k];
    
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }
    
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    rotateArray(arr, n, k);

    std::cout << "Rotated Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

**Explanation:** To rotate an array to the right by `k` positions, we divide the process into three steps. First, we store the first `k` elements in a temporary array. Then, we shift the remaining elements to the left by `k` positions. Finally, we copy the elements from the temporary array back to the end of the original array.