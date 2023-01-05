class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();
        int cnt = 1;
        pair<int, int> temp = make_pair(points[0][0], points[0][1]);
        for(int i = 1; i < n; i++){
            pair<int, int> cur = make_pair(points[i][0], points[i][1]);
            if(cur.first <= temp.second){
                temp.first = max(temp.first, cur.first);
                temp.second = min(temp.second, cur.second);
            }else{
                cnt++;
                temp = cur;
            }
        }
        return cnt;
    }
};