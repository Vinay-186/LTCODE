class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int n = costs.size();
        int i = 0;
        while(i < n && costs[i] <= coins){
            coins -= costs[i];
            i++;
        }
        return i;
    }
};