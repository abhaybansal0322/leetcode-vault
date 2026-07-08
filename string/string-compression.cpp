class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        int i=0;
        int n=chars.size();
        while(i<n)
        {
            char curr_char = chars[i];
            int cnt=0;
            while(i<n && chars[i]==curr_char)
            {
                i++;
                cnt++;
            }

            chars[index]=curr_char;
            index++;
            if(cnt>1){
                string curr_cnt=to_string(cnt);
                for(char &ch : curr_cnt)
                {
                    chars[index]=ch;
                    index++;
                }
            }
            
        }
        return index;
    }
};