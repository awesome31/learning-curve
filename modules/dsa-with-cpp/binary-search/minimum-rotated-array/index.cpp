/**
 * Suppose an array of length n sorted in ascending order is rotated between 1
 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

 [4,5,6,7,0,1,2] if it was rotated 4 times.
 [0,1,2,4,5,6,7] if it was rotated 7 times.
 Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in
 the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

 Given the sorted rotated array nums of unique elements, return the minimum
 element of this array.
 */

#include <iostream>
using namespace std;

int findMin(vector<int> &nums) {
  // This means the array is not rotated.
  if (nums.size() == 1 || nums[0] < nums[nums.size() - 1]) {
    return nums[0];
  }

  int left = 0, right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] > nums[mid + 1]) {
      return nums[mid + 1];
    } else if (nums[mid] < nums[left]) {
      right = mid;
    } else if (nums[mid] > nums[right]) {
      left = mid;
    }
  }

  return -1;
}

int main() {
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

  cout << findMin(nums) << endl;
}
