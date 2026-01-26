// User function Template for C++

class Solution {
  public:
  vector<int>delRow = {-1,0,1,0};
  vector<int>delCol = {0,1,0,-1};
  
  bool isSafe(int &newRow, int &newCol,vector<vector<int>> &grid,vector<vector<int>>&dist,int currNodeDistance){
      return (newRow>=0 && newRow<grid.size() &&
                newCol>=0 && newCol< grid[0].size() &&
                    grid[newRow][newCol]!=0 && dist[newRow][newCol] > currNodeDistance+1 );
  }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        
        int n = grid.size();
        int m = grid[0].size();
        if(grid[destination.first][destination.second]==0)return -1;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second] = 0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{source.first, source.second}});
        
        while(!q.empty()){
            auto [currNodeDistance, coords] = q.front();
            int currX = coords.first;
            int currY = coords.second;
            q.pop();
            
            if(currNodeDistance > dist[currX][currY])continue;
            
            for(int i = 0;i<4;i++){
                int newRow = currX + delRow[i];
                int newCol = currY + delCol[i];
                //check new row and col is valid or not
                //grid[new ROw][newCOl]!=0
                //distance should be minimum
                if(isSafe(newRow, newCol, grid, dist, currNodeDistance)){
                    dist[newRow][newCol] = currNodeDistance +1 ;
                    q.push({dist[newRow][newCol] , {newRow, newCol}});
                }
            }
        }
        
        if(dist[destination.first][destination.second] == INT_MAX)return -1;
        return dist[destination.first][destination.second];
        
    }
};
