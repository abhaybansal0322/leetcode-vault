class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> pos(101);
        for(int i=0;i<n;i++) {
            pos[nums[i]].push_back(i);
        }

        int ans = 0;
        for(int v=1;v<=100;v++) {
            if(pos[v].size() == 3 && pos[v][1] - pos[v][0] == pos[v][2] - pos[v][1]) ans++;
        }

        return ans;
    }
};