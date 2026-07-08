class Solution {
public:
    long long minimumSteps(string s) {
        long long int steps=0;
        int n=s.length();
        int i=n-1;
        long long int count = 0; 
        // while(i < n)
        // {
        //    if(s[i]=='1')
        //    {
        //     count++;
        //    }
        //    else{
        //     steps += count;
        //    }

        //    i++;
        // }

        while(i >= 0)
        {
            if(s[i]=='0')
            {
                count++;
            }
            else{
                steps+=count;
            }
            i--;
        }
        return steps;
    }
};