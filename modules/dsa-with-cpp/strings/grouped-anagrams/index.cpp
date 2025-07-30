/**
 * 0000 0000 0000 0000
 *
 * eab
 * 0000 0000 0001 0011
 *
 * int a = 0;
 * create a mask using 1 << 1;
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void displayVector(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;
}

/**
 * This approach will not work becuase if there are multiple characters, then this will fail.
 */
int createMaskFromString(string &a) {
    int initial = 0;

    for(int i = 0; i < a.size(); i++) {
        int asciiCode = int(a[i]) - 97;
        int mask = 1 << asciiCode;
        initial = initial | mask;
    }

    return initial;
}

vector<int> createFrequencyArrayFromString(string &a) {
    int freq[26] = {0};

    for(int i = 0; i < a.size(); i++) {
        freq[int(a[i]) - 97]++;
    }

    std::vector<int> res(freq, freq + sizeof(freq) / sizeof(freq[0]));
    return res;
}

vector<vector<string> > groupAnagrams(vector<string>& strs) {
    map<vector<int>, vector<string> > m;

    for(int i = 0; i < strs.size(); i++) {
        vector<int> freqArr = createFrequencyArrayFromString(strs[i]);

        if(m.find(freqArr) != m.end()) {
            //I have found it.
            m[freqArr].push_back(strs[i]);
        } else {
            //Not found
            vector<string> s;
            s.push_back(strs[i]);
            m[freqArr] = s;
        }
    }

    vector<vector<string> >  res;

    for (const auto& pair : m) {
        vector<string> temp;
        for(int i = 0; i < pair.second.size(); i++) {
            temp.push_back(pair.second[i]);
        }

        res.push_back(temp);
      }

      return res;
}

int main() {
    string a = "eba";
    string b = "bea";
    string c = "abea";

    vector<string> s;
    s.push_back("eat");
    s.push_back("tea");
    s.push_back("tan");
    s.push_back("ate");
    s.push_back("nat");
    s.push_back("bat");

    vector<vector<string> > res = groupAnagrams(s);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }

        cout << endl;
    }
}
