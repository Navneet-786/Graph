// User function Template for C++

class Solution {
  public:
  vector<int>delRow = {-1,0,1,0};
  vector<int>delCol = {0,1,0,-1};
  
  bool isSafe(vector<vector<int>>& grid,vector<vector<bool>>&visited, int &currRow, int &currCol){
    return (currRow>=0 && currRow<grid.size() &&
        currCol>=0 && currCol<grid[0].size() &&
        !visited[currRow][currCol] && grid[currRow][currCol] == 1);
  }
  void trackThem(vector<vector<int>>& grid,vector<vector<bool>>&visited
  , vector<pair<int,int>>&temp,int &parentX, int &parentY){
      
      queue<pair<int,int>>q;
      q.push({parentX, parentY});
      visited[parentX][parentY] = 1;
      
      while(!q.empty()){
          auto [currX, currY] = q.front();
          q.pop();
          
          int x = (parentX - currX );
          int y = (parentY - currY);
          
          temp.push_back({x,y});
          
          for(int i= 0;i<4;i++){
              int newRow = currX + delRow[i];
              int newCol = currY + delCol[i];
              
              if(isSafe(grid, visited, newRow,newCol)){
                  visited[newRow][newCol]  =1;
                  q.push({newRow, newCol});
              }
          }
      }
      
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<bool>>visited(n, vector<bool>(m,0));
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>>temp;
                    trackThem(grid, visited,temp, i,j);
                    st.insert(temp);
                }
            }
        }
        
        return st.size();
        
    }
};
