// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        for(int viaNode = 0; viaNode<n;viaNode++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(dist[i][viaNode] != 1e8 && dist[viaNode][j] != 1e8)
                    {
                        dist[i][j] = min(dist[i][j],
                                dist[i][viaNode] + dist[viaNode][j]);
                    }
                }
            }
        }
        
    }
};