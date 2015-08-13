#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    bool is_palindrome(int left, int right, string& s) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        if (s.size() == 1) return s;
        
        int longest_length = 1, pos = 0;
        for (int i=0; i<s.size(); i++) {
            for (int j=s.size() - 1; j>i && ((j-i+1) > longest_length); j--) {
                if (is_palindrome(i, j, s)) {
                    cout << i << " " << j << endl;
                    longest_length = j - i + 1;
                    pos = i;
                }
            }
        }
        
        return s.substr(pos, longest_length);
    }
};

int main() {
    string s = "jglknendplocymmvwtoxvebkekzfdhykknufqdkntnqvgfbahsljkobhbxkvyictzkqjqydczuxjkgecdyhixdttxfqmgksrkyvopwprsgoszftuhawflzjyuyrujrxluhzjvbflxgcovilthvuihzttzithnsqbdxtafxrfrblulsakrahulwthhbjcslceewxfxtavljpimaqqlcbrdgtgjryjytgxljxtravwdlnrrauxplempnbfeusgtqzjtzshwieutxdytlrrqvyemlyzolhbkzhyfyttevqnfvmpqjngcnazmaagwihxrhmcibyfkccyrqwnzlzqeuenhwlzhbxqxerfifzncimwqsfatudjihtumrtjtggzleovihifxufvwqeimbxvzlxwcsknksogsbwwdlwulnetdysvsfkonggeedtshxqkgbhoscjgpiel";
    cerr << Solution().longestPalindrome(s);
    return 0;
}
