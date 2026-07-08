class Solution {
    public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int minday = 1 ;
        int maxday = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1 ;
        while(minday<=maxday){
            int mid = minday + (maxday - minday)/2 ;
            if(isPossible(bloomDay, m, k, mid )){
                ans = mid ; // possible answer 
                maxday = mid - 1 ; // search for minimum
            }
            else{
                minday = mid + 1 ; 
            }
        }
        return ans ; 
    }

    bool isPossible(vector<int>& bloomDay , int m , int k , int day)
    {
        int n = bloomDay.size(); 
        int flower = 0 ;
        int bouquet = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(bloomDay[i]<= day){
                flower++ ;
                if(flower == k){
                    bouquet++ ;
                    flower = 0 ; // reset for next bouquet
                }
            }
            else{
                flower = 0 ; // not adjacent 
            }
        }
        return bouquet >= m ; 
    }
   
};