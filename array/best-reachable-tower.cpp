class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {

        int x = center[0];
        int y = center[1];

        vector<int> res(2,INT_MAX);
        int maxi = INT_MIN;

        for(auto& tow : towers) {

            int x1 = tow[0];
            int y1 = tow[1];
            int q = tow[2];

            int dis = abs(x1-x)+abs(y1-y);

            if(dis <= radius) {

                if(q > maxi) {

                    res = {x1,y1};
                    maxi = q;
                }
                else if(q == maxi) {
                    
                    if(x1 < res[0]) {

                        res[0] = x1;
                        res[1] = y1;
                    }
                    else if(x1 == res[0]) {

                        if(y1 < res[1]) {

                            res[0] = x1;
                            res[1] = y1;
                        }
                    }
                }
            }
        }

        if((res[0] == INT_MAX) && (res[1] == INT_MAX)) return {-1,-1};
        return res;
    }
};