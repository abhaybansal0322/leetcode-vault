class Solution {
public:
    int getLength(vector<int>& nums) {
        
        int n = nums.size();
        int maxLen = 1;

        for(int i=0;i<n;i++) {

            map<int,int> mp;
            vector<int> f(n+1,0);
            int mx = 0;
            int s = 0;
            for(int j=i;j<n;j++) {

                if(mp[nums[j]]) {

                    f[mp[nums[j]]]--;
                }
                mp[nums[j]]++;
                f[mp[nums[j]]]++;

                if(mp[nums[j]] > mx) {
                    mx = mp[nums[j]];
                    s = 1;
                }
                else if(mp[nums[j]] == mx) s++;

                int dis = mp.size();
                if(dis == 1) maxLen = max(maxLen,j-i+1);

                else if(mx%2 == 0 && s<dis && f[mx/2] == dis-s) maxLen = max(maxLen,j-i+1);
            }
        }

        return maxLen;
    }
};