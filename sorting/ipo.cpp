class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        
        vector<vector<int>> vec;

        for(int i=0;i<n;i++) {

            vec.push_back({capital[i],profits[i]});
        }

        sort(vec.begin(),vec.end());

        priority_queue<int> pq;
        int i=0;

        while(k--) {

            while(i < n && vec[i][0] <= w) {

                pq.push(vec[i][1]);
                i++;
            }

            if(!pq.empty()) {

                w += pq.top();  pq.pop();

            }

        }

        return w;
    }
};