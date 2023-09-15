class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        int edgesUsed = 0;
        vector<bool> inMST(n);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;
        while(edgesUsed < n){
            int currMinEdge = INT_MAX;
            int curNode = -1;
            for(int node = 0; node < n; node++){
                if(!inMST[node] && currMinEdge > minDist[node]){
                    currMinEdge = minDist[node];
                    curNode = node;
                }
            }
            mstCost += currMinEdge;
            edgesUsed++;
            inMST[curNode] = true;
            for(int nextNode = 0; nextNode < n; nextNode++){
                int w = abs(points[curNode][0] - points[nextNode][0]);
                w += abs(points[curNode][1] - points[nextNode][1]);
                if(!inMST[nextNode] && minDist[nextNode] > w){
                    minDist[nextNode] = w;
                }
            }
        }
        return mstCost;
    }
};