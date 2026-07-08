class Solution {
public:
    void helper(vector<int>& nums , int start , int end)
    {
        int i=start;
        int j=end;

        while(i < j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size())
        {
            k = k%(nums.size());
        }
        helper(nums,0,nums.size()-k-1);
        helper(nums,nums.size()-k,nums.size()-1);

        helper(nums,0,nums.size()-1);
    
    }
};