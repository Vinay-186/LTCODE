class Solution {
public:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    void addNum(int num){
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int num : nums1) addNum(num);
        for(int num : nums2) addNum(num);
        return lo.size() > hi.size() ? lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};