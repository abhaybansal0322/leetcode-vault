class Solution {
public:
    int getLeastFrequentDigit(int n) {
        
        unordered_map<int,int> mp;
        int temp = n;
        int res = INT_MAX;
        int ans;

        while(temp) {

            int num = temp%10;
            temp = temp/10;
            mp[num]++;
        }

        for(auto& m : mp) {

            if(m.second <= res) {

                if(m.second == res) {

                    if(m.first < ans) {

                        ans = m.first;
                    }
                }
                else {

                    res = m.second;
                    ans = m.first;
                }

                
            }
        }

        return ans;
    }
};