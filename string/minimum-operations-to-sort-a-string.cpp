class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end())) return 0;
        if (n <= 2) return -1;

        char lo = *min_element(s.begin(), s.end());
        char hi = *max_element(s.begin(), s.end());

        if (s[0] == lo || s[n - 1] == hi) return 1;

        int countLo = count(s.begin(), s.end(), lo);
        int countHi = count(s.begin(), s.end(), hi);

        bool hiStuckAtFront = (s[0] == hi && countHi == 1);
        bool loStuckAtBack  = (s[n - 1] == lo && countLo == 1);

        if (hiStuckAtFront && loStuckAtBack) return 3;
        return 2;
    }
};