class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack<pair<int,int>> st;  //temp,idx

        int n = temp.size();
        vector<int> answer(n,0);

        for(int i=n-1;i>=0;i--) {

            while(!st.empty() && temp[i] >= st.top().first) {

                st.pop();
            }

            if(!st.empty()) {

                answer[i] = st.top().second - i;
            }

            st.push({temp[i],i});
        }

        return answer;
    }
};