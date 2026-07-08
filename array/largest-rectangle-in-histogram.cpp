class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> stk;
        int n = heights.size();
        int res = INT_MIN;

        for(int i=0;i<n;i++) {

            while(!stk.empty() && heights[stk.top()] > heights[i]) {

                int element = heights[stk.top()];
                stk.pop();

                int nse = i;
                int pse = stk.empty() ?-1 : stk.top();

                res = max(res,element*(nse-pse-1));

            }
            stk.push(i);
        }

        while(!stk.empty()) {

            int nse = n;
            int element = heights[stk.top()];   stk.pop();

            int pse = stk.empty() ? -1 : stk.top();

            res = max(res,element*(nse-pse-1));
        }

        return res;
    }
};