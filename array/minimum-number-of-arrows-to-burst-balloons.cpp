class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        int n = p.size();

        sort(p.begin(),p.end());
        vector<int> prev = p[0];
        int ans=1;

        for(int i=1;i<n;i++)
        {
            if(p[i][0] > prev[1])
            {
                ans++;
                prev = p[i];
            }
            else{
                prev[0]=max(prev[0],p[i][0]);
                prev[1]=min(prev[1],p[i][1]);
            }
        }
        return ans;

        
    }
};