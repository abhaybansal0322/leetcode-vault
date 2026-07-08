class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int count = 0;
        vector<string> result;
        for(string &log : logs)
        {
            if(log.back() <='z' && log.back()>='a')
            {
                result.insert(result.begin(),log);
                count++;
            }
            else{
                result.push_back(log);
            }
        }

        sort(result.begin(),result.begin()+count,[](string s1,string s2)
        {
            string aa = s1.substr(s1.find(' '));
            string bb = s2.substr(s2.find(' '));

            return(aa==bb) ? s1<s2 : aa<bb;

        });

        return result;
        
    }
};