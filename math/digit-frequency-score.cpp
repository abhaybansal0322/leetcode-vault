class Solution {
public:
    int digitFrequencyScore(int n) {
        int temp = n;
        unordered_map<int,int> mp;

        while(temp) {

            int dig = temp%10;
            temp /= 10;
            mp[dig]++;
        }   

        int res = 0;
        for(auto& m : mp) {

            res += m.first*m.second;
        }

        return res;
    }
};