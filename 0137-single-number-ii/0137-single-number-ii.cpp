class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> freq;
        for(int& i : nums){
            freq[i]++;
        }
        for(const pair<int,int>& i : freq){
            if(i.second < 3) return i.first;
        }
        return -1;
    }
};