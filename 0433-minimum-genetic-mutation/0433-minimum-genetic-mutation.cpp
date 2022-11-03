class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> bk,visited;
        bk.insert(bank.begin(), bank.end());
        queue<pair<string,int>> q;
        vector<char> l = {'A', 'C', 'G', 'T'};
        int mini = INT_MAX;
        q.push({start,0});
        visited.insert(start);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            string cur = node.first;
            int steps = node.second;
            if(cur == end) mini = min(mini, steps);
            for(int i = 0; i < 8; i++){
                for(char& c : l){
                    if(c == cur[i]) continue;
                    string temp = cur.substr(0,i) + c + cur.substr(i+1);
                    if(visited.find(temp) == visited.end() && bk.find(temp) != bk.end()){
                        q.push({temp, steps + 1});
                        visited.insert(temp);
                    }
                }
            }
        }
        return mini == INT_MAX? -1 : mini;
    }
};