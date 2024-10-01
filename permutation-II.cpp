#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Permutation {
public:
    vector<int> permutation{};

    Permutation(vector<int>& init) {
        this->permutation = init;
    }

    bool operator==(Permutation const& other) const {
        return !(*this != other);
    }

    bool operator!=(Permutation const& other) const {
        if (this->permutation.size() != other.permutation.size()) return true;

        for (int i = 0; i < this->permutation.size(); i++)
            if (this->permutation[i] != other.permutation[i]) return true;
        return false;
    }

    bool operator<(Permutation const& other) const {
        for (int i = 0; i < this->permutation.size(); i++)
            if (this->permutation[i] > other.permutation[i]) return false;
        return true;
    }
};

struct HashFunction
{
    size_t operator()(Permutation const& other) const
    {
        int tmp = 0;
        for (int i = 0; i < other.permutation.size(); i++) tmp += other.permutation[i] * i;
        return tmp;
    }
};

class Solution {
public:
    void permutation(int n, int index, std::unordered_set<int>& permu, std::unordered_set<Permutation, HashFunction>& permus, vector<int>& nums) {
        if (index == n) {
            vector<int> per{};
            for (auto& num : permu) per.push_back(nums[num]);
            permus.insert(Permutation(per));
            return;
        }

        for (int i = 0; i < n; i++) {
            if (permu.find(i) == permu.end()) {
                permu.insert(i);
                permutation(n, index + 1, permu, permus, nums);
                permu.erase(i);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<int> permu{};
        unordered_set<Permutation, HashFunction> permus{};
        permutation(nums.size(), 0, permu, permus, nums);

        vector<vector<int>> result{};
        for (auto &x: permus) result.push_back(x.permutation);
        return result;
    }
};

int main() {
    vector<int> nums{ 1,2,2,1 };
    Solution solution;
    vector<vector<int>> result = solution.permuteUnique(nums);
    for (auto& per : result) {
        for (auto& num : per) cout << num << " ";
        cout << "\n";
    }
    
    return 0;
}