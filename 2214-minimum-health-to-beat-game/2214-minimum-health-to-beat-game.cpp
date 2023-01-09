class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
       vector<int>::iterator maxi = max_element(damage.begin(), damage.end());
       if(*maxi > armor) *maxi -= armor;
       else *maxi = 0;
       long long ans = 1;
       int n = damage.size();
       for(int i = 0 ;i < n; i++) ans += damage[i];
       return ans;
    }
};