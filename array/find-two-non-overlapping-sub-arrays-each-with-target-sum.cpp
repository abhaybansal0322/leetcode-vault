class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        int currSum = 0;
        int INF = INT_MAX;
        vector<int> bestIdx(n,INF);
        int res = INT_MAX;
        int bestMinLen = INT_MAX;
        
        while(j<n) {
            currSum += arr[j];
            while(currSum > target) {
                currSum -= arr[i];
                i++;
            }

            if(currSum == target) {
                int len = j-i+1;
                if(i>0 && bestIdx[i-1]!=INF) {
                    res = min(res,len+bestIdx[i-1]);
                }
                bestMinLen = min(bestMinLen,len);
            }
            bestIdx[j] = min(bestIdx[j],bestMinLen);
            j++;
        }

        return res == INT_MAX ? -1 : res;
    }
};