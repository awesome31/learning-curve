#include <iostream>
#include <map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  // We have numbers here.
  //
  map<int, int> m;
  vector<int> res;

  for (int i = 0; i < nums.size(); i++) {
    if (m.find(target - nums[i]) != m.end()) {
      res.push_back(i);
      res.push_back(m[target - nums[i]]);

      break;
    }

    m[nums[i]] = i;
  }

  return res;
}

int main() {
  vector<int> A;
  A.push_back(1);
  A.push_back(2);
  A.push_back(3);
  A.push_back(4);
  A.push_back(6);

  vector<int> B = twoSum(A, 8);
  cout << B[0] << " " << B[1] << endl;
}
