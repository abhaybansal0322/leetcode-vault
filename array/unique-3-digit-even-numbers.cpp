class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int have[10] = {};
        for (int d : digits) have[d]++;

        int ans = 0;
        for (int n = 100; n < 1000; n += 2) {
            int need[10] = {};
            need[n / 100]++;
            need[n / 10 % 10]++;
            need[n % 10]++;

            bool ok = true;
            for (int d = 0; d < 10 && ok; d++)
                if (need[d] > have[d]) ok = false;
            ans += ok;
        }
        return ans;
    }
};