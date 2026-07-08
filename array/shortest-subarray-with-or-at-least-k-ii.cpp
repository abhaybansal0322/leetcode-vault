class Solution {
public:

    void Update(int num,vector<int>& vec,int val)
    {
        for(int i=0;i<32;i++)
        {
            if(((num >> i) & 1))
            {
                vec[i] += val;
            }
        }
    }

    int getNum(vector<int>& vec)
    {
        int num = 0;
        for(int i=0;i<32;i++)
        {
            if(vec[i]){
                num |= (1 << i);
            }
        }
        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n= nums.size();
        int i=0;
        int j=0;

        vector<int> vec(32,0);
        int res = INT_MAX;

        while(j < n)
        {
            Update(nums[j],vec,1);

            while(i <= j && getNum(vec)>=k)
            {
                res = min(res,j-i+1);
                Update(nums[i],vec,-1);
                i++;
            }

            j++;
        }

 

        return res == INT_MAX ? -1 : res;
        
    }
};