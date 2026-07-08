class Solution {
public:
    int absDifference(vector<int>& nums, int k) {

        priority_queue<int> pqMax;
        priority_queue<int,vector<int>,greater<int>> pqMin;

        for(auto& num : nums) {

            pqMax.push(num);
            pqMin.push(num);

            if(pqMax.size() > k) pqMax.pop();
            if(pqMin.size() > k) pqMin.pop();
        }

        long long res1=0,res2=0;

        while(!pqMax.empty()) {
            int x = pqMax.top();pqMax.pop();
            res1 +=x;
        }

        while(!pqMin.empty()) {
            int x = pqMin.top();pqMin.pop();
            res2 +=x;
        }

        return res2 - res1;
    }
};