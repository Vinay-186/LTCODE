class Solution {
public:
    bool ok(double mid, vector<int>& stations, int k, int n){
        int count = 0;
        for(int i = 0; i < n-1; i++) count += (int) ((stations[i+1] - stations[i]) / mid);
        return count <= k;
    }
    double minmaxGasDist(vector<int>& stations, int k) {
        double l = 0, r = 1e8;
        int n = stations.size();
        while(r - l > 1e-6){
            double mid = (l + r)/ 2.0;
            if(ok(mid,stations,k,n)) r = mid;
            else l = mid;
        }
        return l;
    }
};