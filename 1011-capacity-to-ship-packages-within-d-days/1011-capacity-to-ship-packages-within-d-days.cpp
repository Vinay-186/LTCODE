class Solution {
public:
    bool ok(vector<int>& warr,int w, int days){
        int cur_sum = 0, cur_days = 1;
        for(int& i : warr){
            cur_sum += i;
            if(cur_sum > w){
                cur_days++;
                cur_sum = i;
            }
        }
        return cur_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while(l < r){
            int w = l + (r - l) / 2;
            if(ok(weights,w,days)) r = w;
            else l = w+1;
        }
        return l;
    }
};