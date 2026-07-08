class Solution {
    typedef long long ll;
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<bool> isPrime(n,true);

        if(n > 0)
            isPrime[0]=false;

        if(n >1)
            isPrime[1]=false;

        for(int i=2;(ll)i*i < n;i++) {

            if(isPrime[i]) {

                for(int j=i*i;j<n;j+=i) {

                    isPrime[j]=false;
                }
            }
        }

        ll sum1 = 0,sum2=0;

        for(int i=0;i<n;i++){

            if(isPrime[i])
                sum1 += nums[i];

            else
                sum2 += nums[i];
        }

        return abs(sum1-sum2);
    }
};