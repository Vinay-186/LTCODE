class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return (a[1] != b[1])? a[1] < b[1] : a[0] < b[0];
    }
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), comp);
        int cur = INT_MIN;
        int ans = 0;
        for(auto& i : p) if(cur < i[0]) cur = i[1],ans++;
        return ans;
    }
};