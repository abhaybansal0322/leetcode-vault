class Solution {
public:
    int nthUglyNumber(int n) {
        // vector<int> mul(3);
        // mul={2,3,5};
        int cnt=0;
        priority_queue<long,vector<long>,greater<long>> pq;
        pq.push(1);
        while(cnt < n-1)
        {
            long val=pq.top();
            pq.pop();
            if(!pq.empty() && pq.top()==val)
            {
                continue;
            }
            else{
                pq.push(val*2);
                pq.push(val*3);
                pq.push(val*5);
                cnt++;
            }
        }

        return pq.top();

        


        
    }
};