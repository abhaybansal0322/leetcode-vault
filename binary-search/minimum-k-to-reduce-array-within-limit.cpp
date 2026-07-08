class Solution {
public:
    int minimumK(vector<int>& nums) {

        long long l = 1;
        long long h = 0;

        h = max((long long)nums.size(),(long long)*max_element(nums.begin(),nums.end()));

        auto func = [&](long long k) {

            long long p = 0;
            long long l = k*k;

            for(int x : nums) {

                p += (x+k-1)/k;
                if(p > l) return false;
            }
            return p <= l;
        };

        long long ans = h;
        while(l<=h) {

            long long mid = l+(h-l)/2;
            if(func(mid)) {

                ans = mid;
                h = mid-1;
            }
            else {

                l = mid+1;
            }
        }

        return ans;
    }
};