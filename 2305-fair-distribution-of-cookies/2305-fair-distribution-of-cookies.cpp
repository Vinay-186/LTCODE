class Solution {
public:
    vector<int> child;
    int n;
    int mini;
    void helper(vector<int>& cookies, int ind, int k){
        if(ind == n){
            mini = min(mini, *max_element(child.begin(), child.end()));
            return;
        }
        for(int i = 0; i < k; i++){
            child[i] += cookies[ind];
            helper(cookies, ind+1, k);
            child[i] -= cookies[ind];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        mini = INT_MAX;
        child.assign(k,0);
        helper(cookies, 0, k);
        return mini;
    }
};