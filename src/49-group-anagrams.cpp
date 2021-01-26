#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            m[key].emplace_back(str);
        }

        vector<vector<string>> ans;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            ans.emplace_back(it->second);
        }

        return ans;
    }
};
