class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int sec = 0;
        int n = s.size();
        string temp = "$";
        while(temp != s){
            temp = s;
            for(int i = 0; i < n-1; i++){
                if(s.substr(i,2) == "01"){
                    swap(s[i], s[i+1]);
                    i++;
                }
            }
            if(temp == s) break;
            sec++;
        }
        return sec;
    }
};