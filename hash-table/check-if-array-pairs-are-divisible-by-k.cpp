class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[((arr[i] % k) + k) % k]++;
        }

        if (m[0] % 2 != 0) {
            return false;
        }

        for (int i = 1; i < n; i++) {
            if (arr[i] % k != 0) {
                int rem = ((arr[i] % k) + k) % k;
                if (m[rem] != m[k - rem]) {
                    return false;
                }
            }
        }

        return true;
    }
};