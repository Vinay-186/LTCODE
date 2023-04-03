class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        if(people.back() > limit) return -1;
        int n = people.size();
        int l = 0, r = n -1 ;
        int count = 0;
        while(l <= r){
            if(people[l] + people[r] <= limit) l++, r--;
            else r--;
            count++;
        }
        return count;
    }
};    