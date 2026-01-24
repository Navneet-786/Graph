class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &pre) {
    
        vector<int>adjList[n];
        
        //create adjList
        for(auto it: pre){
            int v = it[0];
            int u = it[1];
            adjList[u].push_back(v);
        }
        
        
        // create inorder array
        vector<int>indegree(n,0);
        for(int i = 0;i<n;i++){
            for(auto it:adjList[i]){
                indegree[it]++;
            }
        }
        
        //bfs ->khans algo
        queue<int>q;
        //store all the element whose indegree is 0
        for(int i = 0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>res;
        //use BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(auto it:adjList[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(res.size() != n)return {};
        return res;
    }
};