class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        //create adjlsit
        vector<pair<int,int>>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adjList[u].push_back({v,w});
            adjList[v].push_back({u, w});
        }
        
        int sum = 0;
        vector<bool>visited(V,0);
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
            >q;
        q.push({0,0});
        
        while(!q.empty()){
            auto [currWt,currNode ] = q.top();
            q.pop();
            
            if(visited[currNode])continue;
            
            visited[currNode] = 1;
            sum += currWt;
            
            for(auto it:adjList[currNode]){
                if(!visited[it.first]){
                    q.push({it.second, it.first});
                }
            }
        }
        
        return sum;
        
    }
};