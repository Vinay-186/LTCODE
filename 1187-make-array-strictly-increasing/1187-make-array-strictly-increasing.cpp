class Solution {
private : 
    int m = 0, n= 0;
    map<pair<int,int>, int> mp;
    int upper_bound(vector<int>& arr2, int val){
        return std::upper_bound(arr2.begin(), arr2.end(), val) - arr2.begin();
    }
public:
    int dfs(int ind, int prev, vector<int>& arr1, vector<int>& arr2){
        if(ind == m) return 0;
        if(mp.find({ind,prev}) != mp.end()) return mp[{ind,prev}];
        int mini = 1e9;
        if(arr1[ind] > prev){
            mini = dfs(ind+1, arr1[ind] ,arr1, arr2);
        }
        int idx = upper_bound(arr2,prev);
        if(idx < n){
            mini = min(mini, 1 + dfs(ind+1, arr2[idx], arr1,arr2));
        }
        return mp[{ind,prev}] =  mini;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        m = arr1.size();
        n = arr2.size();
        int ans = dfs(0,-1,arr1,arr2);
        return ans < 1e9 ? ans : -1;
    }
};