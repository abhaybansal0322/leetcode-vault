class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        if(s[i]==' ')
        {
            while(i>=0)
            {
                if(s[i]!=' ')
                {
                    break;
                }
                i--;
            }
        }
        int count=0;
        while(i>=0)
        {
            if(s[i]==' ')
            {
                break;
            }
            else{
                count++;
            }
            
            i--;
        }
        return count;
        
    }
};