class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq, tp;
        for(int& i : piles) pq.push(i);
        for(int i = 0; i < k; i++){
            int temp = pq.top();
            pq.pop();
            pq.push(temp - temp/2);
        }
        int sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};