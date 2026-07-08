class Solution {

    int binRef(int x) {

        int i = 30;
        int res = 0;
        while(x) {

            if(x&1) {

                res = res | (1<<i);
            }
            i--;
            x = x >> 1;
        }

        while(!(res&1)) res >>= 1;
        return res;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(), [&] (int x,int y) {

            return make_pair(binRef(x),x) < make_pair(binRef(y),y);
        });
        return nums;
    }
};