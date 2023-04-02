class Solution {
public:
    int m, n;
    int binary(long long val,long long suc, vector<int>& p){
        int l = 0, r = m-1;
        while(l < r){
            int mid = l + (r-l)/2;
            long long prod = val * p[mid];
            if(prod >= suc){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
    long long success)
    {
        sort(potions.begin(), potions.end());
        m = potions.size();
        n = spells.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int ind = binary(spells[i], success, potions);
            if(ind == m-1){
                long long prod = (long long)potions[ind] * spells[i];
                if(prod >= success) ans.push_back(1);
                else ans.push_back(0);
            }else{
                ans.push_back(m - ind);
            }
        }
        return ans;
    }
};

// 1,2,3,4,5
