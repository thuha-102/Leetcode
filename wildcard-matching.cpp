#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void normalizeP(string& p) {
        while (p.find("**") != std::string::npos ||
            p.find("*?") != std::string::npos ||
            p.find("?*") != std::string::npos)
        {
            size_t pos = p.find("**");
            if (pos != std::string::npos) p.replace(pos, 2, "*");

            pos = p.find("*?");
            if (pos != std::string::npos) p.replace(pos, 2, "*");

            pos = p.find("?*");
            if (pos != std::string::npos) p.replace(pos, 2, "*");
        }
    }

    void gennerateP(string &p){
        
    }

    bool isMatch(string s, string p) {
        int index = 0, j = 0;
        normalizeP(p);

        while (index < s.size()) {
            while (index < s.size() && s[index] == p[index]) index++;
            if (index == s.size()) return true;


            if (p[index] == '?') { index++; continue; }
            else if (p[index] == '*') {
                vector<string> stack;

                int genLen = 0, remainLen = p.size() - index - 1 - genLen;
                string genString = "";

                while (index + genLen + remainLen <= s.size()) {
                    stack.push_back(genString);

                    genString += s[index + genLen];
                    genLen++;
                }

            }
            else return false;
            index++;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    string s = "abc", p = "a*";
    std::cout << solution.isMatch(s, p);
    return 0;
}