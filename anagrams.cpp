#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> codes;
        vector<vector<string>> result;
        int lenMap = 0, index = 0;
        string tmp = "";

        for (auto& str : strs) {
            tmp = str;
            sort(str.begin(), str.end());

            index = codes.find(str) == codes.end() ? lenMap : codes.find(str)->second;

            if (index == lenMap){
                codes.insert(pair<string, int>(str, lenMap));
                result.push_back(vector<string>(1, tmp));
                lenMap += 1;
            }
            else result[index].push_back(tmp);
        }
        return result;
    }
};

int main(){
    vector<string> strs{ "eat","tea","tan","ate","nat","bat" };
    vector<vector<string>> result = Solution().groupAnagrams(strs);
    for (auto& re: result){
        for(auto &str:re)   cout<<str<<" ";
        cout<<"\n";
    }
    return 0;
}