class Node{
  public : 
    int sum,i,j;
    Node(int sum, int i, int j){
        this->sum = sum;
        this->i = i;
        this->j = j;
    }
};
class Compare{
public : 
    bool operator()(const Node& n1, const Node& n2)const{
        return n1.sum > n2.sum;
    }
};


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> ans;
        set<pair<int,int>> vis;
        priority_queue<Node, vector<Node>, Compare> pq;
        pq.push({nums1[0]+nums2[0], 0,0});
        vis.insert({0,0});
        while(k-- && !pq.empty()){
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if(i+1 < n && vis.find({i+1,j}) == vis.end()) 
                pq.push({nums1[i+1]+nums2[j], i+1, j}), vis.insert({i+1,j});
            if(j+1 < m &&  vis.find({i,j+1}) == vis.end()) 
                pq.push({nums1[i]+nums2[j+1], i, j+1}), vis.insert({i,j+1});
        }
        return ans;
    }
};