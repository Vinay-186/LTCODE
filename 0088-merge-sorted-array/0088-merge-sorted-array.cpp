class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0 || n == 0){
            if(m == 0){
                nums1 = nums2;
            }
           return; 
        }
        
        int nums_back = m+n-1;
        int nums1_back = m-1;
        int nums2_back = n-1;
        
        while(nums1_back >= 0 && nums2_back >= 0){
            int arr1 = nums1[nums1_back];
            int arr2 = nums2[nums2_back];
            
            if(arr1 > arr2){
                nums1[nums_back--] = arr1;
                nums1_back--;
            }else{
                nums1[nums_back--] = arr2;
                nums2_back--;
            }
        }
        
        while(nums1_back >= 0){
            int arr1 = nums1[nums1_back--];
            nums1[nums_back--] = arr1;
        }
        
        while(nums2_back >= 0){
            int arr2 = nums2[nums2_back--];
            nums1[nums_back--] = arr2;
        }
        
    }
};