class Solution {
  public:
  bool solve(vector<int>adjList[], vector<bool>&visited,int ele){
    
        stack<pair<int,int>>st;
        st.push({ele,-1});
        
        while(!st.empty()){
            auto [node, parent] = st.top();
            st.pop();
            
            if(visited[node])continue;
            
            visited[node] = 1;
            
            for(int i = adjList[node].size()-1;i>=0;i--){
                if(!visited[adjList[node][i]]){
                    st.push({adjList[node][i] , node});
                }
                else{
                    if(adjList[node][i]!=parent){
                        return true;
                    }
                }
            }
            
            
        }
        
        return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
     
        vector<int>adjList[V];
       
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool>visited(V,0);
       
       for(int i = 0;i<V;i++){
           if(!visited[i]){
               if(solve(adjList,visited,i)){
                   return true;
               }
           }
       }
       
       return false;
        
        
    }
};