class Solution {
public:
    long long minMergeCost(vector<vector<int>>& lists) {

        int n = lists.size();
        int m = 1<<n;

        vector<long long> dp(m,LLONG_MAX);
        vector<int> med(m);
        vector<int> len(m);
        vector<int> temp;
        temp.reserve(2000);

        for(int mask = 1;mask<m;mask++) {

            temp.clear();
            int currLen = 0;

            for(int i=0;i<n;i++) {

                if((mask>>i)&1) {

                    temp.insert(temp.end(),lists[i].begin(),lists[i].end());
                    currLen += lists[i].size();
                }
            }

            len[mask] = currLen;
            int mid = (currLen-1)/2;
            nth_element(temp.begin(),temp.begin()+mid,temp.end());
            med[mask] = temp[mid];
        }

        for(int i=0;i<n;i++) {

            dp[1<<i] = 0;
        }

        for(int mask=1;mask<m;mask++) {

            if((mask&(mask-1) == 0)) continue;

            int lenCost = len[mask];
            for(int s = (mask-1)&mask;s>0;s = (s-1)&mask) {

                int comp = mask^s;

                if(s<comp) continue;

                if(dp[s] != LLONG_MAX && dp[comp] != LLONG_MAX) {

                    long long currCost = dp[s]+dp[comp]+lenCost+abs(med[s]-med[comp]);
                    if(currCost<dp[mask]) {

                        dp[mask] = currCost;
                    }
                }
            }
        }
        return dp[m-1];
    }
};