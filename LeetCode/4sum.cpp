class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size();) {
            for (int j=i+1; j<nums.size();) {
                int left = j + 1;
                int right = nums.size() - 1;
                
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        vector<int> sol = {nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(sol);
                        
                        do { left++; }
                        while (left < right && nums[left - 1] == nums[left]);
                        
                        do { right--; }
                        while (left < right && nums[right + 1] == nums[right]);
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
                
                do { j++; }
                while (j < nums.size() && nums[j-1] == nums[j]);
            }
            do { i++; }
            while (i < nums.size() && nums[i-1] == nums[i]);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};
