class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count = n;
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[i] < nums[st.top()]){
                int len = i - st.top();
                count += len-1;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            int len = n - st.top();
            count += len-1;
            st.pop();
        }
        return count;
    }
};