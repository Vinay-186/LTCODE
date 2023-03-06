class Solution {
public:
    void merge(vector<int>& num, int l ,int mid, int r){
        vector<int> ar1, ar2, ar3;
        ar1.insert(ar1.end(), num.begin() + l, num.begin() + mid + 1);
        ar2.insert(ar2.end(), num.begin() + mid + 1, num.begin() + r + 1); 
        int n = mid - l + 1;
        int m = r - mid;
        int i = 0, j = 0 , k = l;
        while(i < n && j < m){
            if(ar1[i] <= ar2[j]) num[k++] = ar1[i++];
            else num[k++] = ar2[j++];
        }
        while(i < n) num[k++] = ar1[i++];
        while(j < m) num[k++] = ar2[j++];
    }
    void divide(vector<int>& num, int l, int r){
        if(l >= r) return;
        int mid = l + (r-l)/2;
        divide(num, l, mid);
        divide(num, mid+1, r);
        merge(num, l ,mid, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        divide(nums, 0, nums.size() - 1);
        return nums;
    }
};