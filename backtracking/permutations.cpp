class Solution {
    vector<vector<int>> result;
    unordered_set<int> st;

    void Solve(vector<int>& temp,vector<int>& nums) {

        if(temp.size()==nums.size()) {

            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++) {

            if(st.find(nums[i])==st.end()) {

                temp.push_back(nums[i]);
                st.insert(nums[i]);
                Solve(temp,nums);
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> temp;
        Solve(temp,nums);
        return result;
    }
};