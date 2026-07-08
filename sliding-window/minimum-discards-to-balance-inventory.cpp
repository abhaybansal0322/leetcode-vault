class Solution {
    const int MAX = 100001;
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {

        vector<int> count(MAX);

        deque<pair<int,int>> dq;
        int n = arrivals.size();
        int d = 0;

        for(int i=1;i<=n;i++) {

            while(!dq.empty() && dq.front().first < i-w+1) {

                count[dq.front().second]--;
                dq.pop_front();
            }

            int temp = arrivals[i-1];

            if(count[temp] < m) {

                dq.push_back(make_pair(i,temp));
                count[temp]++;
            }
            else {

                d++;
            }
        }

        return d;
    }
};