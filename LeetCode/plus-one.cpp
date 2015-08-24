class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        digits[i]++;
        
        while (digits[i] > 9 && i > 0) {
            digits[i-1]++;
            digits[i] = 0;
            i--;
        }
        
        if (digits[0] > 9) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
