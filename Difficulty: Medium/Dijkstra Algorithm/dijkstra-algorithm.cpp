class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        //create adjacency list
        vector<pair<int,int>>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adjList[u].push_back({v,d});
            adjList[v].push_back({u,d});
        }
        
        vector<int>dist(V, 1e9);
        
        dist[src] = 0;
        priority_queue<
                    pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>
                    >pq; //{dist, node}
    pq.push({0,src});
    
    while(!pq.empty()){
        auto [currDist,currNode] = pq.top();
        pq.pop();
        
        if(currDist > dist[currNode]) continue;
        for(auto it:adjList[currNode]){
            int v = it.first;
            int d = it.second;
            int newDist = currDist + d;
            if(newDist < dist[v]){
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    return dist;
    }
};