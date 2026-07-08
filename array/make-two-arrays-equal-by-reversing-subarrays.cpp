class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size()!=arr.size())
        {
            return false;
        }
        int i=0;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        while(i < arr.size())
        {
            if(target[i]!=arr[i])
            {
                return false;
            }
            i++;
        }

        return true;
        
    }
};