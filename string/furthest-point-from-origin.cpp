class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {

        int cntL = 0, cntR = 0, cnt = 0;
        for (char& ch : moves) {

            if (ch == 'L')
                cntL++;
            else if (ch == 'R')
                cntR++;
            else
                cnt++;
        }

        return abs(cntL - cntR) + cnt;
    }
};