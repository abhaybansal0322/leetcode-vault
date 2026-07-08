class Solution {
    vector<int> getNSL(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] > arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }

        return result;
    }

    vector<int> getNSR(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] >= arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }

        return result;
    }

    vector<int> getNML(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                result[i] = -1;
            } else {
                while(!st.empty() && arr[st.top()] < arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }

        return result;
    }

    vector<int> getNMR(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                result[i] = n;
            } else {
                while(!st.empty() && arr[st.top()] <= arr[i]) //strictly less
                    st.pop();
                
                result[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }

        return result;
    }
public:
    long long subArrayRanges(vector<int>& nums) {

        vector<int> NSL = getNSL(nums);
        vector<int> NSR = getNSR(nums);
        vector<int> NML = getNML(nums);
        vector<int> NMR = getNMR(nums);

        long long maxSum=0,minSum=0;

        for(int i=0;i<nums.size();i++)
        {
            long long totalwaysMin = (i-NSL[i])*(NSR[i]-i);
            long long totalwaysMax = (i-NML[i])*(NMR[i]-i);

            maxSum = (maxSum + (totalwaysMax*nums[i]));
            minSum = (minSum + (totalwaysMin*nums[i]));
        }

        return maxSum-minSum;
        
    }
};