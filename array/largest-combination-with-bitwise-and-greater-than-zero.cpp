class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int n=candidates.size();
        vector<int> bitCount(24,0);
        int res = 0;
        for(int i=0;i<24;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((candidates[j] & (1 << i)) != 0)
                {
                    bitCount[i]++;
                }
            }
            res = max(res,bitCount[i]);
        }
        return res;  
    }
};