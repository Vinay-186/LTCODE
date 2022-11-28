class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> A, B;
        map<int, int> l;
        for(vector<int>& i : matches){
            if(l.find(i[0]) == l.end()) l[i[0]] = 0;
            l[i[1]]++;
        }
        for(auto i : l){
            if(i.second == 0) A.push_back(i.first);
            else if(i.second == 1) B.push_back(i.first);
        }
        return {A,B};
    }
};