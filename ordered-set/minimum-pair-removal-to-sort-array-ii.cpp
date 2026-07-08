class Solution {
public:
    typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        
        int n = nums.size();
        vector<ll> temp(n);
        vector<int> prev(n);
        vector<int> next(n);

        for(int i=0;i<n;i++) {

            temp[i] = nums[i];
            prev[i] = i-1;
            next[i] = i+1;
        }

        set<pair<ll,int>> minPairSet;
        
        int bad = 0;
        for(int i=0;i<n-1;i++) {

            if(temp[i] > temp[i+1]) {

                bad++;
            }
            minPairSet.insert({temp[i]+temp[i+1],i});
        }

        int op = 0;
        while(bad > 0) {

            int first  = minPairSet.begin()->second;
            int second = next[first];

            int first_left   = prev[first];
            int second_right = next[second];


            minPairSet.erase(begin(minPairSet));

            if(temp[first] > temp[second]) {
                bad--;
            }

            //{d, (a, b)}
            if(first_left >= 0) {
                if(temp[first_left] > temp[first] &&
                temp[first_left] <= temp[first] + temp[second]) {
                    bad--;
                } 
                else if(temp[first_left] <= temp[first] &&
                temp[first_left] > temp[first] + temp[second]) {
                    bad++;
                }
            }

            //{(a, b), d}
            if (second_right < n) {
                if (temp[second_right] >= temp[second] &&
                    temp[second_right] < temp[first] + temp[second]) {
                    bad++;
                }
                else if (temp[second_right] < temp[second] &&
                         temp[second_right] >= temp[first] + temp[second]) {
                    bad--;
                }
            }

            if(first_left >= 0) {
                minPairSet.erase({temp[first_left] + temp[first], first_left});
                minPairSet.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }

            if(second_right < n) {
                minPairSet.erase({temp[second] + temp[second_right], second});
                minPairSet.insert({temp[first] + temp[second] + temp[second_right], first});
                prev[second_right] = first;
            }

            next[first] = second_right;
            temp[first] += temp[second];

            op++;
        }

        return op;
    }
};