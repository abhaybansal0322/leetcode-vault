
class Solution {
public:
    int smallestAbsent(vector<int>& nums) {

        long long Sum = accumulate(nums.begin(),nums.end(),0);
        double avg = (double)Sum/nums.size();

        int c = max(1, (int)(floor(avg))+1);

        unordered_set<int> pres(nums.begin(),nums.end());

        while(pres.count(c)) {

            c++;
        }

        return c;
        
        
    }
};