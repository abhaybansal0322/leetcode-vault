class Solution {
public:

    int slidingWindow(vector<int>& nums,int mid)
    {
        int cnt=0;
        int i=0;
        int j=1;
        while(j < nums.size())
        {
            while(nums[j]-nums[i] > mid)
            {
                i++;
            }
            cnt += (j-i);
            j++;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {



        // priority_queue<int> pq;
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         int diff=abs(nums[i]-nums[j]);
        //         pq.push(diff);
        //         if(pq.size() > k)
        //         {
        //             pq.pop();
        //         }
        //     }
        // }
        // return pq.top();






        // vector<int> result;
        // for(int i=0;i<nums.size()-1;i++)
        // {
        //     for(int j=i+1;j<nums.size();j++)
        //     {
        //         int diff=abs(nums[i]-nums[j]);
        //         result.push_back(diff);
        //     }
        // }
        // nth_element(result.begin(),result.begin()+k-1,result.end());
        // return result[k-1];

        int res=0;
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums[nums.size()-1]-nums[0];

        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int count=slidingWindow(nums,mid);
            if(count < k)
            {
                l=mid+1;
            }
            else{
                res=mid;
                r=mid-1;
            }
        }
        return res;
 
    }
};