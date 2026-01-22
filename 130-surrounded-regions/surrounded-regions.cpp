class Solution {
public:
bool isValid(int &newRow, int &newCol,vector<vector<bool>>&visited, vector<vector<char>>& board){
    return (newRow>=0 && newRow<board.size() &&
    newCol>=0 && newCol<board[0].size() && 
    !visited[newRow][newCol] && board[newRow][newCol] =='O'
    );
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m =board[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        //extreme column 
        for(int i = 0;i<n;i++){
            if(board[i][0] == 'O'){
                visited[i][0] = 1;
                q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                visited[i][m-1] = 1;
                q.push({i,m-1});
            }
        }

        //extreme rows
        for(int j = 0;j<m;j++){
            if(board[0][j]=='O'){
                visited[0][j] = 1;
                q.push({0,j});
            }
            if(board[n-1][j]=='O'){
                visited[n-1][j] = 1;
                q.push({n-1, j});
            }
        }
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,1,0,-1};
        while(!q.empty()){
            auto [currRow, currCol] = q.front();
            q.pop();

            for(int i = 0;i<4;i++){
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                if(isValid(newRow, newCol, visited, board)){
                    q.push({newRow,newCol});
                    visited[newRow][newCol] = 1;
                }
            }


        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(board[i][j]=='O'  && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};