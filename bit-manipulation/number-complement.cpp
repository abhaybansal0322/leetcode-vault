class Solution {
public:
    int findComplement(int num) {
        int bits_count=floor(log2(num))+1;
        long long ones=((1LL << bits_count)-1);

        return ones^num;
        
    }
};