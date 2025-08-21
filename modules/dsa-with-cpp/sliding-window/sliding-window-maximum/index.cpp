/**
 * You are given an array of integers nums, there is a sliding window of size k
 which is moving from the very left of the array to the very right. You can only
 see the k numbers in the window. Each time the sliding window moves right by
 one position.

 Return the max sliding window.

 Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 Output: [3,3,5,5,6,7]
 */

#include <iostream>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {}

int main() {
  vector<int> nums;

  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(-1);
  nums.push_back(-3);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(7);

  vector<int> res = maxSlidingWindow(nums, 3);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  cout << endl;
}
