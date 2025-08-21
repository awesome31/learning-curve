/**
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 or false otherwise.

 In other words, return true if one of s1's permutations is the substring of s2.

 Input: s1 = "ab", s2 = "eidbaooo"
 Output: true
 Explanation: s2 contains one permutation of s1 ("ba").
 */

#include <iostream>
using namespace std;

bool isAnagram(string A, string B) {
  int M[26] = {0};

  for (int i = 0; i < A.size(); i++) {
    M[int(A[i]) - 97]++;
  }

  for (int i = 0; i < B.size(); i++) {
    M[int(B[i]) - 97]--;
  }

  for (int i = 0; i < 26; i++) {
    if (M[i] != 0) {
      return false;
    }
  }

  return true;
}

bool checkInclusion(string s1, string s2) {
  if (s1.size() > s2.size()) {
    return false;
  }

  string tempString = "";

  for (int i = 0; i < s1.size(); i++) {
    tempString += s2[i];
  }

  for (int i = s1.size(); i < s2.size(); i++) {
    if (isAnagram(tempString, s1)) {
      return true;
    }

    tempString.erase(0, 1);
    tempString += s2[i];
  }

  if (isAnagram(tempString, s1)) {
    return true;
  }

  return false;
}

int main() {
  string s1 = "ab";
  string s2 = "a";

  cout << checkInclusion(s1, s2) << endl;
}
