class Solution {
    bool checkPrime(int num) {
        
        if(num<=1)  return false;
        if(num<=3)  return true;

        if(num%2==0 || num%3==0)    return false;

        for(int i=5;i*i<=num;i+=6) {

            if(num%i==0 || num%(i+2)==0)    return false;
        }

        return true;

        
    }
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int> mp;

        for(auto& num : nums) {
            mp[num]++; 
        }

        for(auto& M : mp) {
            if(checkPrime(M.second))
                return true;
        }

        return false;
    }

};