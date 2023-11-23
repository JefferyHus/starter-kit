#include <iostream>
#include <unordered_set>

void findDuplicate(int arr[], int n) {
  std::unordered_set<int> seen;

  std::cout << "Duplicated: ";

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
  int arr[] = {1, 5, 66, 89, 5, 13, 0, 8, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  findDuplicate(arr, n);

  return 0;
}