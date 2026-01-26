class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // {v, time}
        vector<pair<int,int>>adjList[V];
        
        //create adjList
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adjList[u].push_back({v, t});
            adjList[v].push_back({u, t});
        }
        
        vector<int>minTime(V,INT_MAX);
        vector<int>path(V,0);
        
        priority_queue<
            pair<int, int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        >q;
        
        minTime[0] = 0;
        path[0] = 1;
        q.push({0,0});
        
        while(!q.empty()){
            auto [currTime,currNode] = q.top();
            q.pop();
            
            if(currTime > minTime[currNode])continue;
            
            for(auto it:adjList[currNode]){
                int v = it.first;
                int t = it.second;
                
                int vTime = currTime + t;
                
                //if time is lesser then prev
                if(vTime < minTime[v]){
                    minTime[v] = vTime;
                    q.push({vTime, v});
                    path[v] = path[currNode];
                    
                }
                else if(vTime == minTime[v] ){
                    path[v] = path[v] + path[currNode];
                }   
            }
        }
        
        return path[V-1];
    }
};