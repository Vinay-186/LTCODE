class Solution {
public:
    int m, n, w;
    bool f(vector<vector<char>>& board, string& word,int i, int j, int k){
        if(k >= w) return true;
        if(i < 0 || j < 0 || j == m || i == n || board[i][j] != word[k]) return false;
        bool var = false;
        board[i][j] = '$';
        var = f(board,word,i+1,j,k+1)|f(board,word,i-1,j,k+1)|f(board,word,i,j+1,k+1)|f(board,word,i,j-1,k+1);
        board[i][j] = word[k];
        return var;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        w = word.size();
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(f(board,word,i,j,0)) return true;
        return false;
    }
};