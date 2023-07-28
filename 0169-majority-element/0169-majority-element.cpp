class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_elem = nums[0];
        int count = 0;
        for(int num: nums){
            if(num == maj_elem) count++;
            else count--;
            if(count == 0){
                maj_elem = num;
                count = 1;
            }
        }
        return maj_elem;
    }
};