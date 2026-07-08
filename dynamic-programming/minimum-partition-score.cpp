class Solution {
    struct Line {
        long long m,c;
        long long eval(long long x){return m*x + c;}
        double intersect(const Line& other) const {
            return (double)(other.c - c)/(m-other.m);
        }
    };
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> P(n+1,0);
        for(int i=0;i<n;i++) {
            P[i+1] = P[i]+nums[i];
        }

        const long long INF = 1e18;
        vector<long long> dp(n+1,INF);
        dp[0] = 0;

        for(int step=1;step<=k;step++) {
            vector<long long> nextdp(n+1,INF);
            deque<Line> dq;

            for(int i=0;i<=n;i++) {

                if(i<n && dp[i] != INF) {
                    long long m = -2*P[i];
                    long long c = 2*dp[i] + P[i]*P[i] - P[i];
                    Line newLine = {m,c};

                    while(dq.size() >= 2) {
    
                        if(dq[dq.size()-2].intersect(newLine) <= dq[dq.size()-2].intersect(dq.back())) {
                            dq.pop_back();
                        } else {
                            break;
                        }
                    }
                    dq.push_back(newLine);
                }

                if(i >= step && !dq.empty()) {

                    long long x = P[i];

                    while(dq.size()>=2 && dq[0].eval(x) >= dq[1].eval(x)) {
                        dq.pop_front();
                    }

                    long long bestVal = dq[0].eval(x);
                    nextdp[i] = (bestVal + x*x + x)/2;
                }
            }
            dp = nextdp;
        }

        return dp[n];
    }
};