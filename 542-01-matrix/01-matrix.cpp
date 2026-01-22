class Solution {
private:
bool isSafe(int row, int col, vector<vector<int>>&mat, vector<vector<bool>>&visited){
    int n = mat.size();
    int m = mat[0].size();

    return (row>=0 && row<n && col>=0 && col< m && !visited[row][col]);
}

public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n  = mat.size();
        int m  = mat[0].size();
        
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,0));

        queue<pair<pair<int,int>,int>>q;

        //store all the zeros
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                    visited[i][j]= 1;
                }
            }
        }

           
      vector<int>delRow = {-1, 0, 0, 1};
      vector<int>delCol = {0, -1, 1, 0};


        while(!q.empty()){
            auto ele = q.front();
            q.pop();

            int row = ele.first.first;
            int col = ele.first.second;
            int dis = ele.second;

            ans[row][col] = dis;

            for(int i = 0;i<4;i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isSafe(newRow,newCol,mat, visited)){
                    visited[newRow][newCol] = 1;
                    q.push({{newRow, newCol},dis+1});
                }
            }

            
        }
return ans;
    }
};