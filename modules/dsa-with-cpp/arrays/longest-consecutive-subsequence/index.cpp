/**
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

 You must write an algorithm that runs in O(n) time.

 Example 1:

 Input: nums = [100,4,200,1,3,2,5]
 Output: 4
 Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 Example 2:

 Input: nums = [0,3,7,2,5,8,4,6,0,1]
 Output: 9
 Example 3:

 Input: nums = [1,0,1,2]
 Output: 3
 */

#include <map>
#include <vector>
using namespace std;

int longestConsecutive(vector<int>& nums) {

    map<int, bool> m;



for(int i = 0; i < nums.size(); i++) {
m[nums[i]] = false;
}

int finalMax = 0;

for (const auto& pair : m) {
//Have not visited it yet.
if(!pair.second) {
    int max = 0;
    int temp = pair.first;
    while(m.find(temp) != m.end()) {
        max++;
        m[temp] = true;
        temp = temp + 1;
    }

    if(finalMax < max) {
        finalMax = max;
    }
}
}

return finalMax;
}

int main() {
    vector<int> a = {100,4,200,1,3,2};

    longestConsecutive(a);
}
