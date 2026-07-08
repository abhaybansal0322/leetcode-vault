class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+")
            {
                int One = st.top();
                st.pop();
                int Two = st.top();
                st.pop();

                st.push(Two+One);
            }

            else if(tokens[i]=="*")
            {
                int One = st.top();
                st.pop();
                int Two = st.top();
                st.pop();

                st.push(Two*One);
            }

            else if(tokens[i]=="-")
            {
                int One = st.top();
                st.pop();
                int Two = st.top();
                st.pop();

                st.push(Two-One);
            }

            else if(tokens[i]=="/")
            {
                int One = st.top();
                st.pop();
                int Two = st.top();
                st.pop();

                st.push(Two/One);
            }

            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
        
    }
};