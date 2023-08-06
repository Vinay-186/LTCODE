class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxVal - minVal + 1,0);
        for(int num : nums){
            cnt[num - minVal]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i] == 0) continue;
            pq.push({cnt[i], i + minVal});
            // if(pq.size() == k) break;
        }
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};