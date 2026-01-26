class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        // code here
        int n =edges.size();
        int m = edges[0].size();
        
        vector<pair<int, int>>adjList[V];
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            // u -> {v , time}
            adjList[u].push_back({v, t});
        }
        
        
        vector<int>dist(V,INT_MAX);
        // {time, node}
        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>>q;
        dist[src] = 0; //time take to reach src = 0
        q.push({0,src}); // 0 time required to reach src node
        
        while(!q.empty()){
            auto [currTime,currNode] = q.top();
            q.pop();
            
            //explaore if currTime is lesses otherwise ignore
            if(currTime > dist[currNode])continue;
            
            for(auto it:adjList[currNode]){
                int v = it.first;
                int vTime = it.second + currTime;
                if(vTime < dist[v]){
                    dist[v] = vTime;
                    q.push({vTime, v});
                }
            }
        }
        int minTime = INT_MIN; 
        for(int i = 0;i<V;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            minTime = max(minTime, dist[i]);
        }
        return minTime;
    }
};