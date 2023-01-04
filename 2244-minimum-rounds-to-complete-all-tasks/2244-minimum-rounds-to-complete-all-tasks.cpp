class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> freq;
        int count = 0;
        for(int& i : tasks) freq[i]++;
        for(auto& i : freq){
            if(i.second == 1) return -1;
            if(i.second % 3 == 0) count += i.second /3;
            else count += i.second/3 + 1;
        }
        return count;
    }
};