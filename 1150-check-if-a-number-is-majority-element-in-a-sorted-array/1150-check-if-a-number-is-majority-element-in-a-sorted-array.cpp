class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int count = 0;
        int candidate = -1;// Candidate for Boyer Moore Algo;
        int freq = 0;  // freq of target element in the nums;
        for(int num : nums){
            if(count == 0){
                candidate = num;
            }
            count += (num == candidate)? 1 : -1;
            if(num == target) freq++;
        }
        if(target == candidate && freq > nums.size()/2) return true;
        return false;
    }
};