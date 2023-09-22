class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 1);
        stack<pair<int,int>> st;
        for(int i = 0; i < n-1; i++){
            if(!st.empty() && nums[i] < st.top().first){
                while(!st.empty() && nums[i] < st.top().first){
                    int len = i - st.top().second;
                    count[st.top().second] += len-1;
                    st.pop();
                }
            }
            if(nums[i] <= nums[i+1]) st.push({nums[i], i});
        }
        while(!st.empty()){
            if(st.top().first > nums[n-1]){
                int len = n-1-st.top().second;
                count[st.top().second] += len-1;
                st.pop();
            }else{
                int len = n - st.top().second;
                count[st.top().second] += len-1;
                st.pop();
            }
        }
        return accumulate(count.begin(), count.end(), 0);
    }
};