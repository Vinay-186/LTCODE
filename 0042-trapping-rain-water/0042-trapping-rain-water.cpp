class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0), right(n, 0);
        for(int i = 1; i < n; i++){
            left[i] = max(arr[i-1], left[i-1]);
        }
        
        for(int i = n-2; i >= 0; i--){
            right[i] = max(arr[i+1], right[i+1]);
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int curr = min(left[i], right[i]) - arr[i];
            cnt += curr > 0 ? curr: 0;
        }
        return cnt;
    }
};