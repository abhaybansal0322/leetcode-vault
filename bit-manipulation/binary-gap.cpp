class Solution {
public:
    int binaryGap(int n) {

        if(n==0)    return 0;
        if((n&(n-1)) == 0)  return 0;


        int last = -1;
        int pos = 0;
        int ans = 0;

        while(n) {

            if(n&1) {

                if(last != -1) {

                    ans = max(ans,pos-last);
                }
                last = pos;
            }
            pos++;
            n >>= 1;
        }

        return ans;
    }
};