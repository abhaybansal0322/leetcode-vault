class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        if(n==1)    return 1;
        int curr = 0;

        for(int i=0;i<n;i++) {

            unordered_map<double,int> mp;

            for(int j=0;j<n;j++) {

                if(i!=j) {

                    auto dy = points[j][1]-points[i][1];
                    auto dx = points[j][0]-points[i][0];

                    double theta = atan2(dy,dx);
                    mp[theta]++;

                    curr = max(curr,mp[theta]+1);
                }
                
            }
        }

        return curr;
    }
};