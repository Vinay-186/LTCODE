class Solution {
public:
    bool ok(vector<int>& piles, double k, int h){
        long long count = 0;
        for(int& i : piles) {
            count += ceil((double)i / k);
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(), piles.end());
        long long sum = accumulate(piles.begin(), piles.end(), 0ll);
        long long min = sum / h;
        if(h > sum) return 1;
        int l = min, r = max;
        while(l < r){
            int mid = (l + r) >> 1;
            if(ok(piles,mid,h)) r= mid;
            else l = mid+1;
        }
        return l;
    }
};  