class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        for(int& i :arr) mp[i]++;
        int z = mp.size();
        set<int> st;
        for(auto& i : mp) st.insert(i.second);
        int t = st.size();
        return z == t;
    }
};