class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
        vector<int> result;
        int n = s.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0]=0;
        right[n-1]=0;

        for(int i=1;i<n;i++)
        {
            if(s[i]>s[i-1])
            {
                left[i]=0;
            }
            else{
                left[i] = left[i-1]+1;
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]>s[i+1])
            {
                right[i]=0;
            }
            else{
                right[i] = right[i+1]+1;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(left[i]>=time && right[i]>=time)
            {
                result.push_back(i);
            }
        }

        return result;
    }
};