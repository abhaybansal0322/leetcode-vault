class Solution {
public:
    int n;
    unordered_map<string, int> memo;

    bool checkD(string a, string b) {
        unordered_set<char> s;
        for (char c : a) {
            s.insert(c);
        }
        if (s.size() < a.length()) {
            return true;
        }
        for (char c : b) {
            if (s.find(c) != s.end()) {
                return true;
            }
        }
        return false;
    }

    int helper(vector<string>& arr, int i, string temp) {
        if (i >= n) {
            return temp.length();
        }

        if (memo.count(temp)) {
            return memo[temp];
        }

        int include = 0;
        int exclude = 0;

        if (checkD(arr[i], temp)) {
            exclude = helper(arr, i + 1, temp);
        } else {
            include = helper(arr, i + 1, temp + arr[i]);
            exclude = helper(arr, i + 1, temp);
        }

        return memo[temp] = max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        n = arr.size();

        return helper(arr, 0, temp);
    }
};