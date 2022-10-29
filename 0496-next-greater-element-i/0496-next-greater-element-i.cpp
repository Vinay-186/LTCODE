class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> b;
        map<int,int> rec;
        int n = nums2.size();
        for(int i = n-1; i >= 0; i--){
            while(!b.empty() && b.top() < nums2[i]) b.pop();
            rec[nums2[i]] = (!b.empty())? b.top() : -1;
            b.push(nums2[i]);
        }
        vector<int> res;
        n = nums1.size();
        for(int i = 0 ;i < n; i++)
            res.push_back(rec[nums1[i]]);
        return res;
    }
};