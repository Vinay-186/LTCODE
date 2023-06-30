class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
       int n = prob.size();
       vector<double> prev(target+1, 0), cur(target+1, 0);
       prev[0] = 1;
       for(int i = n-1; i >= 0; i--){
           for(int j = 0; j <= target; j++){
                double pick = (j != 0)? prev[j-1] * prob[i] : 0;
                double notpick = prev[j] * (1-prob[i]);
                cur[j] = pick + notpick;               
           }
           prev = cur;
       }
       return cur[target];
    }
};