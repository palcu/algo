#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, pair<int,int>> hash;
        vector<vector<int>> ret;
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                hash[nums[i]+nums[j]] = make_pair(i, j);
            }
        }
        
        for (int i=0; i<nums.size(); i++) {
            int searched_value = 0 - nums[i];
            auto iter = hash.find(searched_value);
            
            if (iter != hash.end()) {
                pair<int, int> positions = iter->second;
                
                if (positions.first != i && positions.second != i) {
                    vector<int> sol = {i, positions.first, positions.second};
                    sort(sol.begin(), sol.end());
                    ret.push_back(sol);
                }
            }
        }
        return ret;
    }
};

int main() {
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<int> sol = Solution().threeSum(v);
    for(auto i : sol) {
        cout << i << endl;
    }
    return 0;
}
