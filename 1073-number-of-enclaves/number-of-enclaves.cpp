class Solution {
public:
bool isSafe(int &newRow, int &newCol,vector<vector<bool>>&visited,vector<vector<int>>& grid){
    return (newRow>=0 && newRow< grid.size() &&
            newCol>=0 && newCol<grid[0].size() &&
            !visited[newRow][newCol] && grid[newRow][newCol] == 1);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,0));
        queue<pair<int,int>>q;
        
        //extreme column
        for(int i = 0;i<n;i++){
            if(grid[i][0] == 1){
                visited[i][0] = 1;
                q.push({i,0});
            }
            if(grid[i][m-1] == 1){
                visited[i][m-1] = 1;
                q.push({i,m-1}); 
            }
        }
          //extreme rows
        for(int i = 0;i<m;i++){
            if(grid[0][i] == 1){
                visited[0][i] = 1;
                q.push({0,i});
            }
            if(grid[n-1][i] == 1){
                visited[n-1][i] = 1;
                q.push({n-1,i}); 
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

                if(isSafe(newRow,newCol,visited, grid)){
                    visited[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }

        }

        int count = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};