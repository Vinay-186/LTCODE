class Solution {
public:
    bool confusingNumber(int n) {
        if(n < 10 && n != 6 && n != 9) return false;
        else if(n < 10 && (n == 6 || n == 9)) return true;
        set<int> invalid = {2,3,4,5,7};
        vector<int> digi;
        int temp = n;
        while(n != 0){
            int dig = n % 10;
            n/= 10;
            if(invalid.find(dig) != invalid.end()) return false;
            digi.push_back(dig);
        }
        int num = 0;
        for(int& i : digi){
            if(i == 9) num = num * 10 + 6;
            else if(i == 6) num = num * 10 + 9;
            else num = num * 10 + i;
        }
        return num != temp;
    }
};