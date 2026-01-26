class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //{u}-> {v, cost}
        //create a adjacency list
        vector<pair<int,int>>adjList[n];
        
        for(auto it:flights){
            int u = it[0];
            int v = it[1];
            int cost = it[2];
            adjList[u].push_back({v, cost}); //directed graph
        }
        vector<int>dist(n,INT_MAX);//contain the min price
        //{ k, {node, cost}}
        priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>>q;
        dist[src] = 0;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            int stops = q.top().first;
            int currNode = q.top().second.first;
            int cost = q.top().second.second;
            
            q.pop();
            
            //if by chance steps goes beyond k then it is not relevant case
            if(stops > k)continue;
            
            
            for(auto it: adjList[currNode]){
                int nextNode = it.first;
                int nextCost = it.second;
                
                if(cost + nextCost < dist[nextNode] 
                    && stops <= k){
                        dist[nextNode] = cost + nextCost;
                        q.push({stops+ 1, {nextNode, dist[nextNode]}});
                    }
            }
            
        }
        
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
        
        
        
    }
};