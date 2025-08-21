/**
 * Given two strings s and t of lengths m and n respectively, return the minimum
 window substring of s such that every character in t (including duplicates) is
 included in the window. If there is no such substring, return the empty string
 "".

 The testcases will be generated such that the answer is unique.

 Input: s = "ADOBECODEBANC", t = "ABC"
 Output: "BANC"
 Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 from string t
 */

/**
 * Explanation and deep dive into the problem:
 * 1. To validate whether a substring of s has all the elements in t, we need to
 * create a frequency map of t and see if all the elements are 0.
 */
#include <iostream>
#include <map>
#include <sys/syslimits.h>
#include <utility>
using namespace std;

string minWindow(string s, string t) {
  if (t.size() > s.size()) {
    return "";
  }
  if (s.size() == 1 && s == t) {
    return s;
  }

  // One map is going to be for t and other is the window map that will keep
  // changing.
  map<char, int> tMap;
  map<char, int> windowMap;
  for (int i = 0; i < t.size(); i++) {
    windowMap[t[i]] = 0;

    if (tMap.find(t[i]) != tMap.end()) {
      tMap[t[i]]++;
    } else {
      tMap[t[i]] = 1;
    }
  }

  int have = 0;
  int need = t.size();
  int front = 0, rear = 0;
  pair<int, int> p = pair<int, int>(0, 0);
  bool modified = false;

  while (rear < s.size()) {
    // We have found the substring
    if (tMap.find(s[rear]) != tMap.end()) {
      windowMap[s[rear]]++;

      if (windowMap[s[rear]] <= tMap[s[rear]] && windowMap[s[rear]] != 0) {
        have++;
      }
    }

    if (need == have) {
      while (need == have && front <= rear) {
        if (windowMap.find(s[front]) != windowMap.end()) {
          windowMap[s[front]]--;

          if (windowMap[s[front]] < tMap[s[front]]) {
            if ((p.second == 0 && p.first == 0) ||
                rear - front < p.second - p.first) {
              modified = true;
              p.first = front;
              p.second = rear;
            }

            have--;
          }
        }

        front++;
      }
    }

    rear++;
  }

  if (modified) {
    return s.substr(p.first, p.second - p.first + 1);

  } else {
    return "";
  }
}

/**
 * dacbbaca
 * 01234567
 */

int main() { cout << minWindow("abcaabaca", "aba") << endl; }
