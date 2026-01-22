class Solution {
  public:
  
  void visitNodes(vector<int>adjList[],vector<bool>&visited, int node, vector<int>&temp){
      stack<int>st;
      st.push(node);
      while(!st.empty()){
          auto currNode = st.top();
          st.pop();
          
          if(visited[currNode])continue;
          
          temp.push_back(currNode);
          
          visited[currNode] =1;
          
          for(int i = adjList[currNode].size()-1;i>=0;i--){
              int neigh = adjList[currNode][i];
              if(!visited[neigh] ){
                  st.push(neigh);
              }
          }
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        //we created adjacency list
        vector<int>adjList[V];
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool>visited(V,0);
        vector<vector<int>>ans;
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                vector<int>temp;
                visitNodes(adjList, visited,i, temp);
                ans.push_back(temp);
            }
        }
        
        return ans;
        
    }
};
