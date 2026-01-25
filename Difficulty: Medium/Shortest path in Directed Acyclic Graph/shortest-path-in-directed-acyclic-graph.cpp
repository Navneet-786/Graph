// User function Template for C++
class Solution {
  public:
  void doToposort(int node, vector<pair<int,int>>adjList[],
  stack<int>&st, vector<bool>&visited){
    visited[node] = 1;
    
    for(auto it:adjList[node]){
        if(!visited[it.first]){
            doToposort(it.first, adjList,st, visited);
        }
    }
    
    st.push(node);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        //1. create adjList
        vector<pair<int,int>>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            
            adjList[u].push_back({v, d});
        }
        
        //2. do the toposort
        stack<int>st;
        vector<bool>visited(V,0);
        for(int i = 0 ;i<V;i++){
            if(!visited[i]){
               doToposort(i,adjList, st, visited);
            }
        }
        
        
        //3. create a length vector and initialize with INT_MAX
        vector<int>dist(V,1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it:adjList[node]){
                int v = it.first;
                int d = it.second;
                int newLength = dist[node] + d;
                if(newLength < dist[v]){
                    dist[v] = newLength;
                }
            }
            
        }
        
        for(int i = 0;i<V;i++){
            if(dist[i]==1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
        
    }
};
