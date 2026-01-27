// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);
        dist[src] = 0;
        //relax the edges for V-1 times
        for(int i = 0;i<V-1;i++){
            for(auto  it:edges){
                int u = it[0];
                int v = it[1];
                int d = it[2];
                
                if(dist[u] != 1e8 &&  dist[v] > dist[u] + d){
                    dist[v] = dist[u] + d;
                }
            }
        }
        
      
        // till now if negative cycyle is present , we have stable edges
        //but we have to check negative cycle 
        //if negative ccycyle present -> then it will updated on Vth relaxation
        //check for negative cycle
        for(auto it:edges){
             int u = it[0];
                int v = it[1];
                int d = it[2];
                
                if(dist[u]!=1e8  && dist[v] > dist[u] + d){
                   return {-1}; 
                }
        }
        return dist;
        
    }
};
