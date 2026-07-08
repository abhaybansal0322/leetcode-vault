class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int res = x^y;
        int cnt = 0;

        while(res) {

            cnt += (res & 1);
            res >>= 1;
        }

        return cnt;
    }
};