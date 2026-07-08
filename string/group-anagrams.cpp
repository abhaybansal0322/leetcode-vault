class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> result;

        for(int i=0;i<n;i++)
        {
            string temp = strs[i];
            sort(begin(temp),end(temp));

            mp[temp].push_back(strs[i]);
        }

        for(auto &m: mp)
        {
            result.push_back(m.second);
        }

        return result;
        
    }
};