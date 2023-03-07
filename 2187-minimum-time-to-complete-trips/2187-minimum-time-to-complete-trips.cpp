class Solution {
public:
    bool ok(long long t, vector<int>& time, int total){
        long long count = 0;
        for(int& i : time) count += (t / i);
        return count >= total;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0;
        long long min = *min_element(time.begin(), time.end());
        long long r = min * totalTrips;
        while(l < r){
            long long mid = (l + r)/2;
            if(ok(mid,time,totalTrips)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};