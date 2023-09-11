class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        int n = groupSizes.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n ; i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto pair : mp){
            int len = pair.first;
            vector<int> vals = pair.second;
            int cnt = vals.size() / len;
            int i = 0;
            while(cnt--){
                ans.push_back(vector(vals.begin()+i, vals.begin() + i + len));
                i += len;
            }
        }
        return ans;
    }
};