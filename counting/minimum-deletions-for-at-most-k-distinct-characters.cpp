class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int> mp;
        for (char ch : s) {
            mp[ch]++;
        }

        int distinct = mp.size();
        int toRemove = distinct - k;

        if (toRemove <= 0) return 0;

        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;

        for (auto& [ch, freq] : mp) {
            pq.push({freq, ch});
        }

        int ans = 0;
        while (toRemove-- && !pq.empty()) {
            ans += pq.top().first;
            pq.pop();
        }

        return ans;
    }
};
