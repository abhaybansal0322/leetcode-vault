class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        deque<int> dq; // stores indices for max chargeTime in decreasing order
        long long sumRunning = 0;
        int n = chargeTimes.size();
        int l = 0, ans = 0;

        for (int r = 0; r < n; r++) {
            // Maintain decreasing deque for chargeTimes
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[r])
                dq.pop_back();
            dq.push_back(r);

            sumRunning += runningCosts[r];

            // Compute total cost
            while (!dq.empty() && (chargeTimes[dq.front()] + (long long)(r - l + 1) * sumRunning > budget)) {
                if (dq.front() == l) dq.pop_front();
                sumRunning -= runningCosts[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
