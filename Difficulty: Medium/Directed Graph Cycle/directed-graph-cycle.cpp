class Solution {
  public:
  bool solve(vector<int>adjList[], vector<bool>&path ,
   vector<bool>&visited, int node){
       visited[node] = 1;
       path[node] = 1;
       
       for(auto it:adjList[node]){
           if(!visited[it]){
               if(solve(adjList, path, visited,it)){
                   return true;
               }
           }
         else if (path[it]) {
            return true;
            }
       }
       path[node] = 0;
       
       return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
           
        }
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        
        for(int i = 0;i<V;i++){
            if(!visited[i]){
               if( solve(adjList,path,visited, i))return true;
            }
        }
        
        return false;
    }
};