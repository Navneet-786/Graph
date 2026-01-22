class Solution {
public:
bool isValid(int &newRow, int &newCol, vector<vector<bool>>&visited,vector<vector<int>>& grid, int &n, int &m){
    return (newRow>=0 && newRow<n && newCol>=0 && newCol<m
            && !visited[newRow][newCol] && grid[newRow][newCol]==1 );
}
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n, vector<bool>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] ==2){
                    q.push({make_pair(i,j),0});
                    visited[i][j] = 1;
                }
            }
        }
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,1,0,-1};
        int minTime = 0;
        while(!q.empty()){
            auto [cords,time] = q.front();
            q.pop();
            int x = cords.first;
            int y = cords.second;

            minTime = max(minTime, time);
            for(int i = 0;i<4;i++){
                int newRow = x + delRow[i];
                int newCol = y + delCol[i];

                //valid coords
                if(isValid(newRow, newCol,visited, grid, n, m)){
                    q.push({make_pair(newRow,newCol),time+1});
                    visited[newRow][newCol] = 1;
                    grid[newRow][newCol] = 2;
                }
            }
        }
       for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
       }

       return minTime;

    }
};