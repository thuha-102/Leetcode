#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void permutation(int n, int index, std::unordered_set<int> &permu, vector<vector<int>> &result, vector<int> &nums) {
        if (index == n) {
            vector<int> per{};
            for(auto& num: permu) per.push_back(nums[num]);
            result.push_back(per);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (permu.find(i) == permu.end()) {
                permu.insert(i);
                permutation(n, index + 1, permu, result, nums);
                permu.erase(i);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> permu{};
        vector<vector<int>> result{};
        permutation(nums.size(), 0, permu, result, nums);
        return result;
    }
};

int main() {
    vector<int> nums{ 1,2,3 };
    Solution solution;
    vector<vector<int>> result = solution.permute(nums);
    for (auto& per : result) {
        for (auto& num : per) cout << num << " ";
        cout << "\n";
    }
    return 0;
}