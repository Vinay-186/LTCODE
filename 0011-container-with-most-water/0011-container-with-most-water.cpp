class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int left = 0;
        int right = height.size() -1;
        while(left < right){
            int width = right - left;
            maxi = max(maxi, width * min(height[left], height[right]));
            (height[left] <= height[right])? left++ : right--;
        }
        return maxi;
    }
};