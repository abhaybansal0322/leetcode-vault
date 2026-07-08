class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        vector<pair<int,int>> goodPairs;
        
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                int diff = abs(arr[i]-arr[j]);
                if(diff <= a)
                {
                    goodPairs.push_back({i,j});
                }
            }
        }

        int cnt = 0;
        for(auto &P : goodPairs)
        {
            for(int k=0;k<n;++k)
            {
                int i = P.first;
                int j = P.second;

                if(i==k || j==k || k < i || k < j)
                    continue;
                
                if((abs(arr[i]-arr[k]) <= c) && (abs(arr[j]-arr[k]) <= b))
                {
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};