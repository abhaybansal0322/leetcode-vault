// #include<unordered_map>
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
        
//         unordered_map<int,int> ans;
//         int a=nums[0];
//         int val=nums.size()/2;
//         for(int i=0;i<nums.size();i++)
//         {
//             ans[nums[i]]++;
//             if(ans[nums[i]]>val)
//             {
//                a=nums[i];
//                break;
//             }
//         }   
//         return a;
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};