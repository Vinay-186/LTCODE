class Solution {
public:
    int n, days, w;
    bool ok(vector<int>& warr,int cur,int ind){
        if(cur > days) return false;
        if(ind == n){
            if(cur <= days) return true;
            return false;
        }
        int sum = 0;
        for(int i = ind; i <= n; i++){
            if(i == n){
                return ok(warr, cur+1, i);
            }
            if(sum + warr[i] > w){
                if(ok(warr,cur+1,i)){
                    return true;
                }
                break;
            }else{
                sum += warr[i];
            }
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        this->days = days;
        n = weights.size();
        int sum = accumulate(weights.begin(), weights.end(), 0);
        int l = sum / days;
        int h = sum;
        while(l < h){
            w = l + (h - l) / 2;
            if(ok(weights,0,0)){
                h = w;
            }else{
                l = w+1;
            }
        }
        return l;
    }
};