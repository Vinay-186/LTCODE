class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
       return accumulate(damage.begin(), damage.end(), 1ll) - min(*max_element(damage.begin(), damage.end()), armor);
    }
};