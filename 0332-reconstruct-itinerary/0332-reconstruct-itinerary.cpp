class Solution {
public:
    vector<string> ans;
    map<string, multiset<string>> adj;
    void visit(string airport)
    {
        while(adj[airport].size()){
            string next = *adj[airport].begin();
            adj[airport].erase(adj[airport].begin());
            visit(next);
        }
        ans.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(vector<string>& ticket : tickets){
            adj[ticket[0]].insert(ticket[1]);
        }
        visit("JFK");
        return vector(ans.rbegin(), ans.rend());
    }
};