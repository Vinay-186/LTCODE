class Solution {
public:
    int binarySearch(vector<int>& arr, int n){
        int low = 0, high = n-1;
        while(low < high){
            int mid = (low + high) >> 1;
            (arr[mid] == 1)? low = mid + 1 : high = mid;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int n = mat.size();
        int col_size = mat[0].size();
        for(int i = 0; i <n ;i++){
            int count = 0;
            if(mat[i][col_size-1] == 1) count = col_size;
            else count = binarySearch(mat[i], col_size);
            pq.push({count, i});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};