#include <iostream>

void findMaxMin(int arr[], int n, int& min, int& max) {
  min = INT_MAX;
  max = INT_MIN;

  std::cout << "List size: " << n << std::endl;

  for(int i = 0; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }

    if (arr[i] > max) {
      max = arr[i];
    }
  }
}

int main() {
  int arr[] = {2, 3, 55, 0, 10, 9, 19, 99, 301};
  int n = sizeof(arr) / sizeof(arr[0]);
  int min, max;
  
  std::cout << "sizeof arr:" << sizeof(arr) << std::endl;
  std::cout << "sizeof arr[0]:" << sizeof(arr[0]) << std::endl;

  findMaxMin(arr, n, min, max);

  std::cout << "Minimum: " << min << std::endl;
  std::cout << "Maximum: " << max << std::endl;

  return 0;
}