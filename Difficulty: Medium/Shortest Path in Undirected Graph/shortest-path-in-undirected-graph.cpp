class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        //create adjList
        vector<int>adjList[V];
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        //create a length vector
        vector<int>minLength(V,INT_MAX);
        minLength[src] = 0;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            
            //visite all adj
            for(auto it:adjList[currNode]){
                int len = minLength[currNode] + 1; //expected length
                if(len < minLength[it]){
                    minLength[it] = len;
                    q.push(it);
                }
            }
        }
        
        for(int i = 0;i<V;i++){
            if(minLength[i]==INT_MAX){
                minLength[i] = -1;
            }
        }
        return minLength;
    }
};
