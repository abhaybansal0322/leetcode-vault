class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();

        if(n == 1)  return stones[0];
        
        priority_queue<int> pq;
        for(int i=0;i<n;i++)    pq.push(stones[i]);

        while(!pq.empty()) {

            if(pq.size() == 2)  break;

            int y = pq.top();   pq.pop();
            int x = pq.top();   pq.pop();

            pq.push(y-x);
        }

        int x = pq.top();   pq.pop();
        int y = pq.top();   pq.pop();

        return x-y;
        
    }
};