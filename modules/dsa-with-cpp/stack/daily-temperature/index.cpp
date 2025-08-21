/**
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the ith day to get a warmer temperature. If there is no future day
 * for which this is possible, keep answer[i] == 0 instead.
 *
 * [73,74,75,71,69,72,76,73]
 */

#include <iostream>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
  int n = temperatures.size();
  vector<int> res(n, 0);
  stack<int> st;

  for (int i = 0; i < n; i++) {
    while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
      int idx = st.top();
      st.pop();
      res[idx] = i - idx;
    }
    st.push(i);
  }

  return res;
}

int main() {
  vector<int> a;

  //[73,74,75,71,69,72,76,73]

  a.push_back(73);
  a.push_back(74);
  a.push_back(75);
  a.push_back(71);
  a.push_back(69);
  a.push_back(72);
  a.push_back(76);
  a.push_back(73);

  vector<int> res = dailyTemperatures(a);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }

  cout << endl;
}
