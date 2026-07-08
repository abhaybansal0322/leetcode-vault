class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {

        vector<int> k;
        k=nums;

        vector<int> base(31,0);

        for(auto& x : nums) {

            int a = x;

            for(int b=30;b>=0;b--) {

                if(!(a & (1 << b))) {

                    continue;
                }

                if(base[b]) {

                    a = a^base[b];
                }

                else {

                    base[b]=a;
                    break;
                }
                
            }
        }

        int res = 0;

        for(int b=30;b>=0;b--) {

            res = max(res,res^base[b]);
        }

        return res;
    }
};