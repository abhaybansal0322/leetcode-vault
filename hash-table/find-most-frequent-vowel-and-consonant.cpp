class Solution {
public:
    int maxFreqSum(string s) {
      unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};

        int sum1 = 0;
        int sum2 = 0;
        unordered_map<char,int> mp;

        for(auto& ch : s)
            {
                mp[ch]++;
                if(st.find(ch)!=st.end())
                {
                    sum1 = max(sum1,mp[ch]);
                }
                else{
                    sum2 = max(sum2,mp[ch]);
                }
            }

        return sum1+sum2;
    }
};