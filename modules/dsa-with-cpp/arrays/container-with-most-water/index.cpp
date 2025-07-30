/**
 *
 You are given an integer array height of length n. There are n vertical lines
 drawn such that the two endpoints of the ith line are (i, 0) and (i,
 height[i]).

 Find two lines that together with the x-axis form a container, such that the
 container contains the most water.

 Return the maximum amount of water a container can store.

 Notice that you may not slant the container.
 */

#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height) {
  int first = 0;
  int last = height.size() - 1;
  int max = -1;

  while (first < last) {
    if (height[first] < height[last]) {
      // If last is bigger then,
      int waterStored = height[first] * (last - first);

      if (waterStored > max) {
        max = waterStored;
      }

      first++;
    } else {
      // If last is bigger then,
      int waterStored = height[last] * (last - first);

      if (waterStored > max) {
        max = waterStored;
      }

      last--;
    }
  }

  return max;
}

int main() {
  vector<int> A = {4, 8, 6, 2, 5, 4, 8, 3, 7};
  int area = maxArea(A);

  cout << area << endl;
}
