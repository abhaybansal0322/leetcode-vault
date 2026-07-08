class Solution {
public:
    
    int n;
    vector<tuple<int,int,int>> factors;
    int target2, target3, target5;
    
    // memo[(i, e2, e3, e5)] = answer
    map<tuple<int,int,int,int>, long long> memo;
    
    long long solve(int i, int e2, int e3, int e5) {
        
        if (i == n) {
            return (e2 == target2 && e3 == target3 && e5 == target5);
        }
        
        auto key = make_tuple(i, e2, e3, e5);
        if (memo.count(key)) return memo[key];
        
        auto [fa, fb, fc] = factors[i];
        
        long long ans = 0;
        
        // 1) Multiply
        ans += solve(i + 1, e2 + fa, e3 + fb, e5 + fc);
        
        // 2) Divide
        ans += solve(i + 1, e2 - fa, e3 - fb, e5 - fc);
        
        // 3) Leave
        ans += solve(i + 1, e2, e3, e5);
        
        return memo[key] = ans;
    }
    
    
    long long countSequences(vector<int>& nums, long long k) {
        
        n = nums.size();
        target2 = target3 = target5 = 0;
        long long t = k;
        
        while (t % 2 == 0) { target2++; t /= 2; }
        while (t % 3 == 0) { target3++; t /= 3; }
        while (t % 5 == 0) { target5++; t /= 5; }
        
        if (t != 1) return 0; 
        
        for (int x : nums) {
            int a = 0, b = 0, c = 0;
            while (x % 2 == 0) { a++; x /= 2; }
            while (x % 3 == 0) { b++; x /= 3; }
            while (x % 5 == 0) { c++; x /= 5; }
            factors.push_back({a, b, c});
        }
        
        return solve(0, 0, 0, 0);
    }
};