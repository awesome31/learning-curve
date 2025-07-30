/*
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

 The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 You must write an algorithm that runs in O(n) time and without using the division operation.

 Example 1:

 Input: nums = [1,2,3,4]
 Output: [24,12,8,6]
 Example 2:

 Input: nums = [-1,1,0,-3,3]
 Output: [0,0,9,0,0]
 */

#include <iostream>
#include <vector>
using namespace std;

void displayVector(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> res = nums;
    vector<int> final(nums.size());

    if(nums.size() == 1) {
        return nums;
    }

    int leftSum = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i] * leftSum;
        leftSum = nums[i];
    }

    int rightSum = res[res.size() - 1];
    for(int i = res.size() - 2; i >= 0; i--) {
        res[i] = res[i] * rightSum;
        rightSum = res[i];
    }


    for(int i = 0; i < res.size(); i++) {
        if(i == 0) {
            final[i] = res[1];
        } else if(i == res.size() - 1) {
            final[i] = nums[nums.size() - 2];
        } else {
            final[i] = nums[i - 1] * res[i + 1];
        }
    }


    return final;
}

int main() {
    vector<int> v;
    v.push_back(-1);

    vector<int> a = productExceptSelf(v);

    displayVector(a);
}
