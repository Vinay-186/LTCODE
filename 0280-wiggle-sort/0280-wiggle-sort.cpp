class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int i = 0, j = n-1;
        int t = 0;
        while(t < n){
            if(i == j){
                nums[t++] = temp[i];
            }else{
                nums[t++] = temp[i];
                nums[t++] = temp[j];
                i++, j--;
            }
        }
    }
};