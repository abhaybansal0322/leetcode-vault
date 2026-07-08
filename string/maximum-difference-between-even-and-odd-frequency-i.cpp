class Solution {
public:
    int maxDifference(string s) {
        vector<int> vec(26,0);
        int maxOdd = INT_MIN;
        int maxEven =INT_MAX;

        for(int i=0;i<s.length();i++)
        {
            vec[s[i]-'a']++;
        }

        for(int i=0;i<26;i++)
        {
            if(vec[i]!=0)
            {
                if(vec[i]%2==0)
                {
                    maxEven = min(maxEven,vec[i]);
                }
                else{
                    maxOdd = max(maxOdd,vec[i]);
                }
            }
            
        }

        return maxOdd-maxEven;

        
    }
};