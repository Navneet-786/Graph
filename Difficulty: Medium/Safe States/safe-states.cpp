class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            //we reverse v->u
            adjList[v].push_back(u);
        }
        
        vector<int>indegree(V,0);
        for(int i = 0;i<V;i++){
            for(auto it:adjList[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i = 0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>safe;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            safe.push_back(node);
            
            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return safe;
    }
};