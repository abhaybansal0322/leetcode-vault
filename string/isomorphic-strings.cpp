class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }

        unordered_map<char,char> m_st,m_ts;
        int i=0;
        while(i<s.length())
        {
           if(m_st.count(s[i])!=0 && m_st[s[i]]!=t[i])
           {
            return false;
           }
           if(m_ts.count(t[i])!=0 && m_ts[t[i]]!=s[i])
           {
            return false;
           }
           else{
            m_st[s[i]]=t[i];
            m_ts[t[i]]=s[i];
           }
           i++;
        
        }

        return true;
              
    }
};