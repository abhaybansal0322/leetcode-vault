class Solution {
public:
    // Helper function to compute digit sum
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Create a vector of pairs: (digit sum, number, original index)
        vector<pair<pair<int, int>, int>> sorted_nums;
        for (int i = 0; i < n; ++i) {
            sorted_nums.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        // Sort based on (digit sum, number)
        sort(sorted_nums.begin(), sorted_nums.end());

        // Build the position map to detect cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            // If already in the correct place or already visited
            if (visited[i] || sorted_nums[i].second == i) continue;

            // Count the size of this cycle
            int cycle_size = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = sorted_nums[j].second;
                cycle_size++;
            }

            // If cycle_size > 1, we need (cycle_size - 1) swaps
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }

        return swaps;
    }
};