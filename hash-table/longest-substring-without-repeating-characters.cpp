class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i=0;
        int j=0;
        int n = s.length();
        unordered_map<char,int> mp;

        while(j < n)
        {
            mp[s[j]]++;

            while(mp[s[j]] > 1)
            {
                mp[s[i]]--;
                i++;
            }

            ans = max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};