class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size();) {
            int left = i+1;
            int right = nums.size()-1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    vector<int> sol = {nums[i], nums[left], nums[right]};
                    ret.push_back(sol);
                    
                    do { left++; }
                    while (left < right && nums[left - 1] == nums[left]);
                    
                    do { right--; }
                    while (left < right && nums[right + 1] == nums[right]);
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
            
            do { i++; }
            while (i < nums.size() - 1 && nums[i - 1] == nums[i]);
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
