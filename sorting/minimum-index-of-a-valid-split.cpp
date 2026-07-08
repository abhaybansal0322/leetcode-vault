class Solution {
    int findMaj(vector<int>& nums)
    {
        int maj = -1;
        int count= 0;
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                maj = nums[i];
                count++;
            }
            else if(maj==nums[i])
            {
                count++;
            }
            else{
                count--;
            }
        }
        return maj;
    }
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int maj = findMaj(nums);
        int majCnt=0;

        for(int &num : nums)
        {
            if(num==maj)
            {
                majCnt++;
            }
        }

        int currCount= 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==maj)
            {
                currCount++;
            }

            int n1 = i+1;
            int n2 = n-n1;
            int rem = majCnt-currCount;

            if((currCount*2 > n1) && (rem*2 >n2))
            {
                return i;
            }
        }
        return -1;
    }
};