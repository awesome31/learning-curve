/**
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

 Notice that the solution set must not contain duplicate triplets.

 Example 1:

 Input: nums = [-1,0,1,2,-1,-4]
 Output: [[-1,-1,2],[-1,0,1]]
 Explanation:
 nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 The distinct triplets are [-1,0,1] and [-1,-1,2].
 Notice that the order of the output and the order of the triplets does not matter.
 Example 2:

 Input: nums = [0,1,1]
 Output: []
 Explanation: The only possible triplet does not sum up to 0.
 Example 3:

 Input: nums = [0,0,0]
 Output: [[0,0,0]]
 Explanation: The only possible triplet sums up to 0.
 */

#include <iostream>
#include <map>
using namespace std;

void traverseVector(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

void seperateNegativeAndPositive(vector<int> &nums) {
    int first = 0;
    int last = nums.size() - 1;

    while(first < last) {
        while(nums[first] <= 0) first++;
        while(nums[last] > 0) last--;

        if(first < last) {
            int temp = nums[first];
            nums[first] = nums[last];
            nums[last] = temp;
        }
    }
}

vector<vector<int> > threeSum(vector<int> &nums) {
    vector<vector<int> > res;
    seperateNegativeAndPositive(nums);

    map<int, bool> m;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] > 0) {
            m[nums[i]] = true;
        }
    }
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    traverseVector(nums);

    threeSum(nums);
}
