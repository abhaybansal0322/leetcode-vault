class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> result;
        int m = rolls.size();
        int sum =
            accumulate(rolls.begin(), rolls.end(), 0); // Sum of existing rolls

        // Calculate the required total sum of all (m + n) rolls
        int total_sum = (m + n) * mean;

        // Calculate the required sum for the missing rolls
        int req_sum = total_sum - sum;

        // Check if it's possible to distribute the required sum among n dice
        if (req_sum < n || req_sum > 6 * n) {
            return {}; // It's impossible to distribute this sum
        }

        // Distribute the sum as evenly as possible
        int base_val = req_sum / n;  // Base value for each roll
        int remainder = req_sum % n; // Remainder to distribute

        // Fill result with base_val, adding 1 to the first 'remainder' rolls
        for (int i = 0; i < n; ++i) {
            if (i < remainder) {
                result.push_back(base_val + 1); // Add 1 to handle the remainder
            } else {
                result.push_back(base_val);
            }
        }

        return result;
    }
};
