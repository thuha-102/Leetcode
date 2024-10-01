#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, len = nums.size();
        vector<int> dp;

        for (int i = 0; i < len; i++) dp.push_back(100000);

        dp[0] = 0;
        for (int i = 0; i < len; i++) {
            step = nums[i];
            if (i + step >= len) step = len - i - 1;

            while (step > 0) {
                dp[i + step] = min(dp[i] + 1, dp[i + step]);
                step -= 1;
            }
        }

        return dp[len - 1];
    }
};

int main(){
    vector<int> nums{ 2,3,1,1,4 };
    Solution solution;
    cout << solution.jump(nums) << endl;
    return 0;
}