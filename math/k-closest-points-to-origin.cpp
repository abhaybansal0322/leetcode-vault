class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto myFunc = [](vector<int> &a,vector<int> &b)
        {
            long long dis1 = 1LL *(a[0]*a[0] + a[1]*a[1]);
            long long dis2 = 1LL *(b[0]*b[0] + b[1]*b[1]);
          
            return dis1 < dis2;
        };

        priority_queue<vector<int>,vector<vector<int>>,decltype(myFunc)> pq(myFunc);

        for(vector<int>& point : points)
        {
            pq.push(point);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while(!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
        
    }
};