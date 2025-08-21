/**
 * Given an numsay of integers nums which is sorted in ascending order, and an
 integer target, write a function to search target in nums. If target exists,
 then return its index. Otherwise, return -1.

 You must write an algorithm with O(log n) runtime complexity.
 */

#include <iostream>
using namespace std;

int search(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return -1;
}

/**
 * [-1,0,3,5,9,12]
 */
int main() {
  vector<int> nums = {-1, 0, 3, 5, 9, 12};

  for (int i = 0; i < nums.size(); i++) {
    cout << search(nums, nums[i]) << endl;
  }
}
