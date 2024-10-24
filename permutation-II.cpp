#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

class Permutation {
public:
    vector<int> permutation{};

    Permutation(vector<int>& init) {
        this->permutation = init;
    }

    bool operator<(Permutation const& other) const {
        return this->permutation < other.permutation;
    }
};

class Solution {
public:
    void permutation(int n, int index, std::unordered_set<int>& permu, std::set<Permutation>& results, vector<int>& nums) {
        if (index == n) {
            vector<int> per{};
            for (auto& num : permu) per.push_back(nums[num]);
            results.insert(Permutation(per));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (permu.find(i) == permu.end()) {
                permu.insert(i);
                permutation(n, index + 1, permu, results, nums);
                permu.erase(i);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<int> permu{};
        set<Permutation> permus{};
        permutation(nums.size(), 0, permu, permus, nums);

        vector<vector<int>> result{};
        for (auto& x : permus) result.push_back(x.permutation);
        return result;
    }
};

int main() {
    vector<int> nums{ -1,2,-1,2,1,-1,2,1 };
    Solution solution;
    vector<vector<int>> result = solution.permuteUnique(nums);
    for (auto& per : result) {
        for (auto& num : per) cout << num << " ";
        cout << "\n";
    }
    return 0;
}