class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int sz = strs[0].size();
        int count = 0;
        for(int i = 0; i < sz; i++){
            for(int j = 1; j < n; j++){
                if(int(strs[j][i]) < int(strs[j-1][i])){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};