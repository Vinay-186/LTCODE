class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int maxi = people.back();
        if(maxi > limit) return -1;
        int n = people.size();
        int l = 0, r = n -1 ;
        int count = 0;
        vector<int> vis(n, 0);
        while(l <= r){
            if(people[l] + people[r] <= limit){
                // vis[l] = vis[r] = 1;
                l++, r--;
            }else{
                r--;
            }
            count++;
        }
        // for(int i = 0; i < n; i++){
        //     if(!vis[i]) count++;
        // }
        return count;
    }
};    