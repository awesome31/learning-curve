/**
 *A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

 Given a string s, return true if it is a palindrome, or false otherwise.



 Example 1:

 Input: s = "A man, a plan, a canal: Panama"
 Output: true
 Explanation: "amanaplanacanalpanama" is a palindrome.
 Example 2:

 Input: s = "race a car"
 Output: false
 Explanation: "raceacar" is not a palindrome.
 Example 3:

 Input: s = " "
 Output: true
 Explanation: s is an empty string "" after removing non-alphanumeric characters.
 Since an empty string reads the same forward and backward, it is a palindrome.
 */

#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    /*
     * 47-57: Numbers
     * 97-122: Lowercase letters
     * 65-90: Uppercase letters
     */
    char a = 'Z';

    string sanitized;

    for(int i = 0; i < s.size(); i++) {
        if(int(s[i]) >= 97 && int(s[i]) <= 122) {
            sanitized.push_back(s[i]);
        } else if(int(s[i]) >= 47 && int(s[i]) <= 57) {
            sanitized.push_back(s[i]);
        } else if(int(s[i]) >= 65 && int(s[i]) <= 90) {
            sanitized.push_back(char(int(s[i]) + 32));
        }
    }

    int first = 0;
    int last = sanitized.size() - 1;

    while(first < last) {
        if(sanitized[first] != sanitized[last]) {
            return false;
        }

        first++;
        last--;
    }


    return true;
}

int main() {
    cout << isPalindrome("    ") << endl;
}
