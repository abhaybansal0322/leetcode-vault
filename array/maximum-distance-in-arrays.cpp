class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MAX=arrays[0].back();
        int MIN=arrays[0].front();
        int res=INT_MIN;

        for(int i=1;i<arrays.size();i++)
        {
            int currMax=arrays[i].back();
            int currMin=arrays[i].front();

            res = max({res,abs(MIN-currMax),abs(MAX-currMin)});
            MAX=max(MAX,currMax);
            MIN=min(MIN,currMin);
        }
        return res;
        
    }
};