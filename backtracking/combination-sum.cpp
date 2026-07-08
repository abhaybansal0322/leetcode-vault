class Solution {
    // set<vector<int>> st;
    vector<vector<int>> result;

    void Solve(vector<int>& candidates,int curr,int target,vector<int>& temp,int start) {

        if(curr > target)
            return;

        if(curr == target) {

            // if(st.find(temp) == st.end()) {

                result.push_back(temp);
                // st.insert(temp);
            // }
            return;
        }

        for(int i=start;i<candidates.size();i++) {

            temp.push_back(candidates[i]);
            curr += candidates[i];
            Solve(candidates,curr,target,temp,i);
            temp.pop_back();
            curr -= candidates[i];
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int curr = 0;
        vector<int> temp;
        Solve(candidates,curr,target,temp,0);

        return result;
        
    }
};