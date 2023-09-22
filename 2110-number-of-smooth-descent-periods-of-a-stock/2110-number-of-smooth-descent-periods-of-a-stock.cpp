class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 0;
        int n = prices.size();
        stack<int> st;
        for(int i = 0; i <n ;i++){
            if(!st.empty() && (prices[i] > prices[st.top()] || prices[st.top()] - prices[i] != 1)){
                while(!st.empty()){
                    count += (i - st.top());
                    st.pop();
                }
            }
            if(st.empty()) st.push(i);
            else if(prices[i] - prices[st.top()] == -1) st.push(i);
        }
        
        while(!st.empty()){
            count += (n-st.top());
            st.pop();
        }
        return count;
    }
};