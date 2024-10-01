#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int leftMax = height.front(), rightMax = height.back(), area = 0;
        int left = 1, right = height.size() - 2;

        while (left <= right) {
            if (leftMax <= rightMax) {
                if (height[left] < leftMax) area += leftMax - height[left];
                else leftMax = height[left];
                left++;
            }
            else {
                if (height[right] < rightMax) area += rightMax - height[right];
                else rightMax = height[right];
                right--;
            }
        }
        return area;
    };
};

int main()
{
    Solution solution;
    vector<int> heights{ 0,1,0,2,1,0,1,3,2,1,2,1 };
    std::cout << solution.trap(heights);
    return 0;
}