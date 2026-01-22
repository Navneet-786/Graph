class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        
        int n = adj.size();
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(0);
        visited[0] = 1;
        
        vector<int>ans;
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
        return ans;
        
        
    }
};