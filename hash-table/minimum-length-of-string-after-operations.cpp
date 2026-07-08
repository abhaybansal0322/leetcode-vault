class Solution {
public:
    int minimumLength(string s) {

        sort(s.begin(),s.end());
        int n=s.size();
        int sub = 0;

        for(int i=0;i<n;i++)
        {
            int count = 1;
            while(i+1 < n && s[i]==s[i+1])
            {
                count++;
                i++;
            }

            if(count < 3)
            {
                continue;
            }
            else if((count & 1)==1)
            {
                sub+=count-1;
            }
            else{
                sub+=count-2;
            }
        }




        return s.size()-sub;
        
    }
};