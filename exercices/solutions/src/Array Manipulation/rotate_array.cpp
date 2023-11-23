#include<iostream>

void rotateLeftArray(int arr[], int n, int k) {
  int temp[k];

  for(int i = 0; i < k; i++) {
    temp[i] = arr[i];
  }

  for(int i = k; i < n; i++) {
    arr[i - k] = arr[i];
  }

  for(int i = 0; i < k; i++) {
    arr[n - k + i] = temp[i];
  }
}

void rotateRightArray(int arr[], int n, int k) {
  int temp[k];

  for(int i = n - k; i < n; i++) {
    temp[i - (n - k)] = arr[i];
  }

  for(int i = n - k - 1; i >= 0; i--) {
    arr[i + k] = arr[i];
  }

  for(int i = 0; i < k; i++) {
    arr[i] = temp[i];
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;

  rotateLeftArray(arr, n, k);

  std::cout << "Right Rotate Array: ";
  for(int i = 0; i < n; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  int larr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int ln = sizeof(larr) / sizeof(larr[0]);
  int lk = 3;

  rotateRightArray(larr, ln, lk);

  std::cout << "Left Rotate Array: ";
  for(int i = 0; i < ln; i++) {
    std::cout << larr[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}