class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    int findPrime(int num) {
        for (int i = num - 1; i >= 2; --i) {
            if (isPrime(i)) return i;
        }
        return 0; // Never Reached
    }

    bool helper(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {    
        if (helper(nums)) {
            return true;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int value = findPrime(nums[i]);
            while (i > 0 && nums[i] - value <= nums[i - 1] && value > 0) {
                value = findPrime(value);
            }
            nums[i] -= value;

            if (i > 0 && nums[i] <= nums[i - 1]) {
                return false;
            }
        }
        
        return helper(nums);
    }
};
