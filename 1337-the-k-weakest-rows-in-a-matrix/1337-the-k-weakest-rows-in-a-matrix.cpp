class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        int n = mat.size();
        for(int i = 0; i <n ;i++){
            int count = 0;
            for(int j : mat[i]) if(j) count++;
            if(pq.size() == k){
                if(pq.top().first > count){
                    pq.pop();
                    pq.push({count, i});
                }
            }else{
                pq.push({count, i});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return vector<int>(ans.rbegin(), ans.rend());
    }
};