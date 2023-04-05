class Solution {
public:
    int n ;
    bool valid(vector<int>& nums, long long mid){
        long long sum = 0; 
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum > mid * (i+1)) return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        n = nums.size();
        int l = 0, mid, h = *max_element(nums.begin(), nums.end());
        while(l < h){
            mid = (l + h) >> 1;
            if(valid(nums, mid)){
                h = mid;
            }else{
                l = mid+1;
            }
        }
        return h;
    }
};