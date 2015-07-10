#include <vector>
#include <utility>
#include <iostream>
using namespace std;

const int N = 10007;

class Solution {
    vector<pair<int, int> > hash[N];

public:
    int search_for(int x) {
        int key = x % N;
        key = key > 0 ? key : -key;

        for (int i=0; i<hash[key].size(); i++) {
            if (hash[key][i].first == x)
                return hash[key][i].second;
        }
        return -1;
    }

    void insert_in_hash(int x, int pos) {
        int key = x % N;
        key = key > 0 ? key : -key;

        hash[key].push_back(make_pair(x, pos));
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++) {
            int solution = search_for(target-nums[i]);
            if (solution >= 0) {
                vector<int> sol;
                if (i < solution)
                    sol = {i+1, solution+1};
                else
                    sol = {solution+1, i+1};
                return sol;
            } else insert_in_hash(nums[i], i);
        }
    }
};

int main() {
    vector<int> v = {-1,-2,-3,-4,-5};
    Solution sol;
    vector<int> x = sol.twoSum(v, -8);
    for(auto i : x)
        cout << i << endl;
    return 0;
}
