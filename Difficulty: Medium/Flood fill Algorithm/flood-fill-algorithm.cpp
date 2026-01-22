class Solution {
  public:
  bool isValid(int &newRow, int &newCol,vector<vector<int>>& images,
   vector<vector<bool>>&visited,int &targetColor){
      return (newRow>=0 && newRow<images.size() &&
              newCol>=0 && newCol<images[0].size() &&
              !visited[newRow][newCol] &&
              images[newRow][newCol] == targetColor);
  }
    vector<vector<int>> floodFill(vector<vector<int>>& images, int sr, int sc,
                                  int newColor) {
        int n = images.size();
        int m = images[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        //we are using BFS
        queue<pair<int, int>>q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        
        int targetColor = images[sr][sc];
        vector<int>delRow = {-1,0,1,0};
        vector<int>delCol = {0,1,0,-1};
        while(!q.empty()){
            auto [currX, currY] = q.front();
            q.pop();
            
            images[currX][currY] = newColor;
            
            for(int i = 0;i<4;i++){
                int newRow = currX + delRow[i];
                int newCol = currY + delCol[i];
                
                if(isValid(newRow, newCol, images, visited,targetColor)){
                    images[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                    visited[newRow][newCol] = 1;
                }
            }
            
            
        }
        return images;
        
    }
};