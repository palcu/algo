class Solution {
public:
    int titleToNumber(string s) {
        int multiple = 1,
            sol = 0;
        
        for (int i=1; i<s.size(); i++) {
            multiple *= 26;
        }
        
        for (auto c : s) {
            sol += multiple * (c - 'A' + 1);
            multiple /= 26;
        }
        
        return sol;
    }
};
