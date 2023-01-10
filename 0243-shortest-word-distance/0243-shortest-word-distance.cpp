class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        map<string, vector<int>> mp;
        int n = wordsDict.size();
        for(int i = 0 ;i < n; i++) mp[wordsDict[i]].push_back(i);
        vector<int> w1 = mp[word1];
        vector<int> w2 = mp[word2];
        int mini = INT_MAX;
        for(int& i : w1) for(int& j : w2) mini = min(mini, abs(i-j));
        return mini;
    }
};