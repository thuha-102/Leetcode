#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element
{
    int index, value;
    Element(int i, int v) : index(i), value(v) {}

    bool operator<(const Element &a) const
    {
        if (this->value == a.value)
            return this->index < a.index;
        return this->value > a.value;
        // sort by value to large to small
    }
};

class Solution
{
public:
    int calculateWhite(int l, int r, vector<Element> &candidates)
    {
        if (l >= r || candidates.size() <= 1)
            return 0;

        Element left = candidates[0];
        int index = 0, white = 0;
        while (index + 1 < candidates.size() && left.value == candidates[index + 1].value)
            index++;
        if (index == 0)
        {
            white = (left.value - candidates[index + 1].value) * (r - l);
            candidates[index].value = candidates[index + 1].value;
            index++;
        }

        vector<Element> leftC{}, rightC{};
        int endL = candidates[index].index;
        if (candidates[0].index < endL)
        {
            leftC.push_back(candidates[0]);
            endL = candidates[0].index;
        }
        else
            leftC.push_back(candidates[index]);

        while (index + 1 < candidates.size() && candidates[index].value == candidates[index + 1].value)
            index++;
        int startR = candidates[index].index;
        if (candidates[0].index > startR)
        {
            rightC.push_back(candidates[0]);
            startR = candidates[0].index;
        }
        else
            rightC.push_back(candidates[index]);

        // std::cout<<white<<"\n";
        for (int i = index + 1; i < candidates.size(); i++)
        {
            if (candidates[i].index <= endL)
                leftC.push_back(candidates[i]);
            if (candidates[i].index >= startR)
                rightC.push_back(candidates[i]);
        }
        return white + calculateWhite(l, endL, leftC) + calculateWhite(startR, r, rightC);
    }

    bool checkPossible(vector<int> &heights)
    {
        int hole = 0, index = 0;
        while (index + 1 < heights.size())
        {
            if (heights[index] > heights[index + 1])
                hole = -1;
            else
            {
                if (hole == -1)
                    return true;
            }
            index++;
        }
        return false;
    }

    int trap(vector<int> &height)
    {
        if (height.size() <= 1)
            return 0;
        bool possible = checkPossible(height);
        if (!possible)
            return 0;

        int black = 0, white = 0;
        vector<Element> candidates{};

        for (int i = 0; i < height.size(); i++)
        {
            candidates.push_back(Element(i, height[i]));
            black += height[i];
        }
        sort(candidates.begin(), candidates.end());

        int area = candidates[0].value * candidates.size();
        white = calculateWhite(0, candidates.size() - 1, candidates);

        return area - white - black;
    };
};

int main()
{
    Solution solution;
    vector<int> heights{2, 0, 2};
    std::cout<<heights.size()<<"\n";
    std::cout<<solution.trap(heights);
    return 0;
}