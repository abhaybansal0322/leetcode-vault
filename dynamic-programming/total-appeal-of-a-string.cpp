class Solution {
    typedef long long ll;
public:
    long long appealSum(string s) {
        ll ans =0;
        int n = s.length();
        unordered_map<char,int> mp;

        for(int i=0;i<n;++i)
        {
            char ch = s[i];
            int start = mp.count(ch) ? mp[ch]+1 : 0;

            ans += (ll) (i-start+1)*(n-i);
            mp[ch]=i;
        }

        return ans;
    }
};