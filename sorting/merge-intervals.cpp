class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();

        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);

        for(auto& interval : intervals)
        {
            auto curr = res.back();

            if(curr[1]>=interval[0] && curr[1]<=interval[1])
            {
                res.pop_back();
                res.push_back({curr[0],interval[1]});
            }
            else if(curr[1]>=interval[1])
            {
                continue;
            }
            else{
                res.push_back({interval[0],interval[1]});
            }
        }

        return res;


    }
};