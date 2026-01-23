class Solution {
  public:
  
  bool solve(int node, vector<int>adjList[],vector<bool>&visited,
  vector<int>&color){
      color[node] = 0; //first node is 0 color
      visited[node] = 1;
      queue<int>q;
      q.push(node);
      
      while(!q.empty()){
          int currNode = q.front();
          q.pop();
          
          for(auto &it: adjList[currNode]){
              if(!visited[it]){
                  visited[it] = 1;
                  color[it] = !color[currNode];
                  q.push(it);
              }
              else{
                  if(color[it] == color[currNode])return false;
              }
          }
      }
      
      return true;
      
  }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        int n = edges.size();
        int m = edges[0].size();
        
        vector<int>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
       vector<bool>visited(V,0);
       vector<int>color(V,-1);
       for(int i = 0;i<V;i++){
           if(!visited[i]){
              if(!solve(i, adjList,visited, color))return false;
           }
       }
        return true;
    }
};