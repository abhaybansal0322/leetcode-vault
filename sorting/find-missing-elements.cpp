class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        vector<bool> isPresent(101,false); 
        vector<int> res;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto& num : nums) {

            if(num < mini)  mini = num;
            if(num > maxi)  maxi = num;

            isPresent[num] = true;
        }

        for(int i=0;i<101;i++) {

            if(i > mini && i < maxi && !isPresent[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};