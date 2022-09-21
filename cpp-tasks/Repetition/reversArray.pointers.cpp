#include <iostream>

int main() {
  int arr[5] = {5, 3, 6, 9 ,2};
  int *p=arr;
  std::cout<<"Array in reverse:\n";
  for(int i = 4; i >= 0; i--) {
    std::cout << *(p+i) << "\n";
  }
  return 0;
}