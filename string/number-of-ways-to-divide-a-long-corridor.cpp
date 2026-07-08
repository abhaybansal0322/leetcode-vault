class Solution {
    int M = 1e9+7;
public:
    int numberOfWays(string corridor) {
        
        int n = corridor.length();
        vector<int> seatIdx;
        for(int i=0;i<n;i++) {

            if(corridor[i] == 'S')   seatIdx.push_back(i); 
        }

        if(seatIdx.size() % 2 != 0) return 0;
        if(seatIdx.size() == 0) return 0;

        if(seatIdx.size() == 2) return 1;

        int prevIdx = seatIdx[1];
        long long res = 1;
        for(int i=2;i<seatIdx.size();i+=2) {

            int len = seatIdx[i]-prevIdx;
            res = res*len % M;
            prevIdx = seatIdx[i+1];
        }

        return res;
        
    }
};