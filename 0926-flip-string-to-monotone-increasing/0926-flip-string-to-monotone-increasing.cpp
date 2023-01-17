class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> cur(2,0), prev(2,0);
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0 ; j <= 1; j++){
                if(j == 0){
                    if(s[i] == '0') cur[0] = prev[0];
                    else cur[0] = min(1 + prev[0], prev[1]);
                }else{
                    if(s[i] == '0') cur[1] = 1 + prev[1];
                    else cur[1] = prev[1];
                }
            }
            prev = cur;
        }
        return prev[0];
    }
};