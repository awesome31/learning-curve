#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Array {
public:
  int *A;
  int size;
  int length;

  void display() {
    cout << "Elements of Array are: ";
    for (int i = 0; i < length; i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }

  void add(int value) {
    if (size == length) {
      throw std::runtime_error("Cannot add more values to the array!");
    } else {
      A[length] = value;
      length++;
    }
  }

  void insertElement(int position, int value) {
    int currentLength = length;

    if (position > size || length == size) {
      throw std::runtime_error("Insertion failed.");
    }

    while (currentLength != position) {
      A[currentLength] = A[currentLength - 1];
      currentLength--;
    }

    A[position] = value;
    length++;
  }

  void deleteElement(int position) {
    if (position > length) {
      throw std::runtime_error("Deletion failed.");
    }

    while (position != length - 1) {
      A[position] = A[position + 1];
      position++;
    }

    length--;
  }

  /**
   * Linear search can be improved using
   * 1. transposition. The idea of transposition is that, suppose I am searching
   * for an element, then there is a possibility I search for it again.
   * 2. Move to head: Here if I search for something, I can move it to the
   * first.
   */
  int linearSearch(int value) {
    for (int i = 0; i < length; i++) {
      if (A[i] == value) {
        return i;
      }
    }

    return -1;
  }

  /**
   * Binary Search
   * 1. The array should be sorted.
   * 2. It is done in log(n) time.
   */
  int binarySearch(int value) {
    int l = 0, r = length - 1, m;

    while (l < r) {
      m = floor(l + r / 2);
      if (A[m] == value) {
        return m;
      } else if (A[m] > value) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return -1;
  }

  int max() {
    if (length == 0) {
      return 0;
    }

    int max = A[0];

    for (int i = 1; i < length; i++) {
      if (A[i] > max) {
        max = A[i];
      }
    }

    return max;
  }

  void rotateRightArray() {
    int firstEl = A[0];
    for (int i = 1; i < length; i++) {
      A[i - 1] = A[i];
    }

    A[length - 1] = firstEl;
  }
};

int main() {
  Array Arr;
  cout << "Please enter the size of the array: ";
  cin >> Arr.size;
  Arr.A = new int[Arr.size];
  Arr.length = 0;

  int n;
  cout << "Enter how many numbers you want to add to the array: ";
  cin >> n;
  cout << "Cool. Enter all " << n << " digits one by one: " << endl;

  for (int i = 0; i < n; i++) {
    cin >> Arr.A[i];
  }
  Arr.length = n;

  // Arr.add(2);
  // Arr.display();
  // Arr.insertElement(3, 6);
  // Arr.display();
  // Arr.deleteElement(3);
  // Arr.display();
  // cout << Arr.linearSearch(2) << endl;
  Arr.display();
  cout << Arr.binarySearch(3) << endl;
  cout << Arr.max() << endl;
  Arr.rotateRightArray();
  Arr.display();
}
