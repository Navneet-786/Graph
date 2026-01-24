class Solution {
  public:
  void dfs(int node, vector<int>adjList[],vector<bool>&visited,
   stack<int>&st){
       visited[node] = 1;
       
       //visit first all its neightbours
       for(auto it:adjList[node]){
           if(!visited[it]){
               dfs(it, adjList, visited, st);
           }
       }
       
       //last visite the node itsef after visited all its neighbour
       st.push(node);
   }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int>adjList[V];
        
        //create adjList
        for(auto &it:edges){
            int u = it[0];
            int v = it[1];
            
            adjList[u].push_back(v);
        }
        
        vector<bool>visited(V,0);
        stack<int>st;
        
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(i, adjList, visited, st);
            }
        }
        
        vector<int>ans;
        while(!st.empty()){
            int ele = st.top();
            st.pop();
            ans.push_back(ele);
        }
        
        return ans;
    }
};