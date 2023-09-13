class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int min_candies = n;
        vector<int> freq(n, 0);
        freq[0] = (n > 1 && ratings[0] > ratings[1])? 1 : 0;
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]) freq[i] = freq[i-1] + 1;
        }
        for(int i = n-2; i >=0; i--){
            if(ratings[i] > ratings[i+1]) freq[i] = max(freq[i], 1+freq[i+1]);
        }
        return accumulate(freq.begin(), freq.end(), min_candies);
    }
};